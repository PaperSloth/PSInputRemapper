# PSInputRemapper
PaperSlothInputRemapper

UE4での入力のKeyConfig設定用のPlugin

(ProjectNames/Plugins/)以下にこのプロジェクトを追加して使用してください

動作確認は4.24.3で行いました

設定内容はChangeActionMappingに成功した際に保存される

ProjectSettingsに反映され、Saved/Config/Windows/Input.ini に保存される

Package作成後はSaved/Config/WindowsNoEditor/Input.ini に書き込まれる



## TODO
- サンプル用のLevelの用意
- Axis対応

## Node List
![CurrentNode](https://user-images.githubusercontent.com/8968076/81571032-5cf6fc80-93dc-11ea-8979-8a7e82b272ad.png)

## Example
ThirdPersonTemplateのJumpキーのGamePadでのRemapping
例では固定でJumpの割り当て変更を行っているため、FPS Templateでも動作します
![Example](https://user-images.githubusercontent.com/8968076/81718639-f266bf00-94b6-11ea-9c09-241454479c5d.png)
