set(PACKAGE_NAME medusa)
set(IGNORE_PATTERNS "/\\\\.git")
set(PACKAGE_FILE_NAME PACKAGE_NAME)

set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION ".")
include(InstallRequiredSystemLibraries)

if (UNIX)
  set(CPACK_GENERATOR "TGZ")
  set(CPACK_SOURCE_GENERATOR "TGZ")
endif (UNIX)

if (WIN32)
  set(CPACK_GENERATOR "NSIS")
  set(CPACK_SOURCE_GENERATOR "ZIP")
  set(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\medusa.swap.gs")
  set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}\\\\medusa.ico")
  set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}\\\\medusa.ico")
  set(CPACK_NSIS_INSTALLED_ICON_NAME "${CMAKE_CURRENT_SOURCE_DIR}\\\\medusa.ico")
  set(CPACK_PACKAGE_ICON "${CMAKE_CURRENT_SOURCE_DIR}\\\\medusa.bmp")
  set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An interactive disassembler")
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
  set(CPACK_NSIS_MODIFY_PATH OFF)
  set(CPACK_NSIS_CREATE_ICONS
    "CreateShortCut '\$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\${PROJECT_NAME} (Qt).lnk' '\$INSTDIR\\\\${PROJECT_NAME}_qt.exe'"
  )
  set(CPACK_NSIS_DELETE_ICONS
    "!insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
    Delete \\\"$SMPROGRAMS\\\\$MUI_TEMP\\\\${PROJECT_NAME} (Qt).lnk\\\"
    "
  )
endif (WIN32)

set(CPACK_PACKAGE_EXECUTABLES "medusa" "medusa")

include(CPack)