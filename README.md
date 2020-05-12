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
動作環境はWindowsPCです
MacOSで動くかは手元で動作環境がないため未確認です


## TODO
- サンプル用のLevelの用意
- Axis対応


## Node List
![Allnode](https://user-images.githubusercontent.com/8968076/81718758-1924f580-94b7-11ea-9530-c601396206f1.png)


## Example
ThirdPersonTemplateのJumpキーのGamePadでのRemapping<br>
例では固定でJumpの割り当て変更を行っているため、FPS Templateでも動作します<br>
InputTypeによって書き換え先のキーを変えているため、Gamepadにしている場合にはキーボードが押されても変更されない仕様です<br>
同様にInputTypeがKeyboardの場合にはGamepad側のキーに影響がありません<br>
![Jump](https://user-images.githubusercontent.com/8968076/81720062-d95f0d80-94b8-11ea-930e-d134b7b7712a.png)


## できないこと
- Keyboard/Gamepadで複数のキーを登録できない<br>
  例えば前進を「W」と「↑」に割り当てる等<br>
- デフォルトに戻す<br>
  設定変更前情報を保存していないため、書き換えた後にデフォルト設定に戻す機能がない<br>
  事前にゲーム側で情報を保持しておき、戻すなどゲーム側での実装が必要
- Ctrl/Alt/Shift + Keyの設定<br>
  現段階では用意していません。単一のキーでの動作のみとなります。
