# PSInputRemapper
PaperSlothInputRemapper<br>
UE4での入力のKeyConfig設定用のPlugin<br>
(ProjectNames/Plugins/)以下にこのプロジェクトを追加して使用してください<br>
<br>
動作確認は4.24.3で行いました<br>
設定内容はChangeActionMappingに成功した際に保存される<br>
ProjectSettingsに反映され、Saved/Config/Windows/Input.ini に保存される<br>
Package作成後はSaved/Config/WindowsNoEditor/Input.ini に書き込まれる<br>
<br>
## TODO
- サンプル用のLevelの用意
- Axis対応
<br>
## Node List
![Allnode](https://user-images.githubusercontent.com/8968076/81718758-1924f580-94b7-11ea-9530-c601396206f1.png)
<br>
## Example
ThirdPersonTemplateのJumpキーのGamePadでのRemapping<br>
例では固定でJumpの割り当て変更を行っているため、FPS Templateでも動作します<br>
InputTypeによって書き換え先のキーを変えているため、Gamepadにしている場合にはキーボードが押されても変更されない仕様です<br>
同様にInputTypeがKeyboardの場合にはGamepad側のキーに影響がありません<br>
![Example](https://user-images.githubusercontent.com/8968076/81718639-f266bf00-94b6-11ea-9c09-241454479c5d.png)
