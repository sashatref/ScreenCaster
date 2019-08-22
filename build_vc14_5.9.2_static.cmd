SET APP_NAME=ScreenCastter
SET BUILD_TYPE=release
SET QT_VER=QT_5_9_2_VC_14_STATIC
SET DEST_PATH=%cd%\%APP_NAME%_%QT_VER%

powershell build.ps1 ..\HelperLibrary\src\HelperLibrary.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY
powershell build.ps1 ..\PropertyBrowser3\src\PropertyBrowser3.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY
powershell build.ps1 ..\CustomWidgets\src\CustomWidgets.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY
%BUILD_TYPE% DEPLOY
powershell build.ps1 ..\CustomStylePlugin\src\CustomStylePlugin.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY

powershell build.ps1 ..\HttpServer2\src\HttpServer2.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY

powershell build.ps1 src\ScreenCaster.pro %QT_VER% %DEST_PATH% %BUILD_TYPE% DEPLOY


powershell cleanUpAfterBuild.ps1 %DEST_PATH%


pause