#############################################################################
# Makefile for building: FireEmu
# Generated by qmake (3.1) (Qt 6.5.0)
# Project:  FireEmu.pro
# Template: app
# Command: D:/DEVKIT/Qt/6.5.0/mingw_64/bin/qmake.exe -o Makefile FireEmu.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = D:/DEVKIT/Qt/6.5.0/mingw_64/bin/qmake.exe
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = cp -f
INSTALL_PROGRAM = cp -f
INSTALL_DIR   = cp -f -R
QINSTALL      = D:/DEVKIT/Qt/6.5.0/mingw_64/bin/qmake.exe -install qinstall
QINSTALL_PROGRAM = D:/DEVKIT/Qt/6.5.0/mingw_64/bin/qmake.exe -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
IDC           = idc
IDL           = midl
ZIP           = 
DEF_FILE      = 
RES_FILE      = 
SED           = sed
MOVE          = mv -f
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: FireEmu.pro ../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/win32-g++/qmake.conf ../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/spec_pre.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/device_config.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/sanitize.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/gcc-base.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/g++-base.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/windows-vulkan.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/g++-win32.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/windows-desktop.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/qconfig.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_freetype.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_libpng.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_core.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_core_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_dbus.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designer.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_gui.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_help.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_help_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssettings.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_linguist.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_network.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_network_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_opengl.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_png_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qml.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltyperegistrar_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quick.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickeffects_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_sql.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svg.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_testlib.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_tools_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uitools.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_widgets.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_xml.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt_functions.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt_config.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/win32-g++/qmake.conf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exclusive_builds.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/toolchain.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/default_pre.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/default_pre.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resolve_config.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exclusive_builds_post.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/default_post.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/entrypoint.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/precompile_header.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/warn_on.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resources_functions.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resources.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/moc.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/opengl.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/uic.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qmake_use.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/file_copies.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/windows.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/testcase_targets.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exceptions.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/yacc.prf \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/lex.prf \
		FireEmu.pro \
		../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Widgets.prl \
		../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Gui.prl \
		../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Core.prl \
		../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6EntryPoint.prl \
		../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/build_pass.prf
	$(QMAKE) -o Makefile FireEmu.pro
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/spec_pre.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/device_config.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/sanitize.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/gcc-base.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/g++-base.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/windows-vulkan.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/g++-win32.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/common/windows-desktop.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/qconfig.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_freetype.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_ext_libpng.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_concurrent.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_core.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_core_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_dbus.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designer.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designer_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_gui.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_gui_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_help.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_help_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssettings.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_linguist.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_network.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_network_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_opengl.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_png_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_printsupport.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qml.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qml_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltest.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmltyperegistrar_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quick.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quick_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickeffects_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_sql.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_sql_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svg.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svg_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_testlib.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_tools_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uitools.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_widgets.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_xml.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_xml_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt_functions.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt_config.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/win32-g++/qmake.conf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exclusive_builds.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/toolchain.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/default_pre.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/default_pre.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resolve_config.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exclusive_builds_post.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/default_post.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/entrypoint.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/precompile_header.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/warn_on.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qt.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resources_functions.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/resources.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/moc.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/opengl.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/uic.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/qmake_use.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/file_copies.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/win32/windows.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/testcase_targets.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/exceptions.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/yacc.prf:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/lex.prf:
FireEmu.pro:
../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Widgets.prl:
../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Gui.prl:
../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6Core.prl:
../../DEVKIT/Qt/6.5.0/mingw_64/lib/Qt6EntryPoint.prl:
../../DEVKIT/Qt/6.5.0/mingw_64/mkspecs/features/build_pass.prf:
qmake: FORCE
	@$(QMAKE) -o Makefile FireEmu.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

.SUFFIXES:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile