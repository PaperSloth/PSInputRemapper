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

## Node一覧
![CurrentNode](https://user-images.githubusercontent.com/8968076/81571032-5cf6fc80-93dc-11ea-8979-8a7e82b272ad.png)

## 使用例
ThirdPersonTemplateのJumpキーのGamePadでのRemapping
![Remap](https://user-images.githubusercontent.com/8968076/81571247-a3e4f200-93dc-11ea-96e3-8bef57e54c3d.png)
