#ifndef _MEDUSA_
#define _MEDUSA_

#include "medusa/namespace.hpp"
#include "medusa/binary_stream.hpp"
#include "medusa/types.hpp"
#include "medusa/export.hpp"
#include "medusa/architecture.hpp"
#include "medusa/loader.hpp"
#include "medusa/database.hpp"
#include "medusa/serialize.hpp"
#include "medusa/disassembler.hpp"

#include <vector>
#include <iostream>
#include <iomanip>

#include <boost/shared_ptr.hpp>

#ifdef _MSC_VER
# pragma warning(disable: 4251)
#endif

MEDUSA_NAMESPACE_BEGIN

//! Medusa is a main class, it's able to handle almost all sub-classes.
class Medusa_EXPORT Medusa
{
public:
                                  Medusa(void);
                                  Medusa(std::wstring const& rFilePath);
                                 ~Medusa(void);

                                  /*! This method opens a file for being disassembled.
                                   * It returns nothing but could throws excption @see Exception
                                   * \param rFilePath is the path to the file.
                                   */
  void                            Open(std::wstring const& rFilePath);

                                  //! This method closes the current disassembled file and cleans all resources.
  void                            Close(void);

  void                            Load(Serialize& rSrlz);
  void                            Save(Serialize& rSrlz);

                                  //! This method returns available architectures. @see Architecture
  Architecture::VectorPtr const&  GetArchitectures(void) const { return m_Architectures; }
                                  //! This method returns available loaders. @see Loader
  Loader::VectorPtr const&        GetSupportedLoaders(void) const { return m_Loaders; }
                                  //! This methods returns availables serializers. @see Serialize
  Serialize::VectorSPtr&          GetSerializes(void) { return m_Serializes; }
                                  //! This methods loads all modules.
  void                            LoadModules(std::wstring const& rModulesPath);

                                  /*! This method starts the disassembling.
                                   * \param pLoader is the selected Loader.
                                   * \param pArch is the selected Architecture.
                                   */
  void                            Disassemble(Loader::Ptr pLoader, Architecture::Ptr pArch);

                                  //! This method returns the current database.
  Database&                       GetDatabase(void) { return m_Database; }
  Database const&                 GetDatabase(void) const { return m_Database; }

                                  //! This method makes a fully filled Address if possible. @see Address
  TAddressPtr                     MakeAddress(TOffset Offset);
  TAddressPtr                     MakeAddress(TBase Base, TOffset Offset);
  TAddressPtr                     MakeAddress(Loader::Ptr pLoader, Architecture::Ptr pArch, TOffset Offset);
  TAddressPtr                     MakeAddress(Loader::Ptr pLoader, Architecture::Ptr pArch, TBase Base, TOffset Offset);

                                  //! This method is used for logging purpose and must be used like std::cout.
  static std::ostream&            Log(void)   { return std::cout;   }
  static std::wostream&           wLog(void)  { return std::wcout;  }

private:
  FileBinaryStream        m_FileBinStrm;
  Database                m_Database;
  Architecture::VectorPtr m_Architectures;
  Loader::VectorPtr       m_Loaders;
  Serialize::VectorSPtr   m_Serializes;
  Disassembler            m_Disasm;
};

MEDUSA_NAMESPACE_END

#endif // _MEDUSA_