# PSInputRemapper
PaperSlothInputRemapper<br>
UE4での入力のKeyConfig設定用のPluginとそのSample Project<br>
(ProjectNames/Plugins/)以下をコピーしてお使いのプロジェクトに追加して使用してください<br>
<br>
設定内容はUpdateActionMappingに成功した際に保存される<br>
更新時にProjectSettingsに反映され、Saved/Config/Windows/Input.ini に保存される<br>
Package作成後はSaved/Config/WindowsNoEditor/Input.ini に書き込まれる<br>
キー情報を追加する機能は用意していないため、事前にKeyboardとGamepadの情報をProjectSettingsに追加しておく必要があります。


## 動作環境
Version  : UE4.24.3<br>
  更新すればUE4.25.0 でも動作するとは思いますが、未確認です。<br>
Platform : 動作環境はWindows + PC環境のみです<br>
MacOSで動くかは手元で動作環境がないため未確認です
スマホ/VR系の入力には対応していません(VRのコントローラーとGamepadの両方を設定するとVR側が上書きされます)<br>


## 本Pluginの標準実装でできないこと
機能として今はサポートしていないもので、工夫すればできるものとできないものがあります。<br>
- Keyboard/Gamepadで複数のキーを登録できない<br>
  例えば前進を「W」と「↑」に割り当てる等<br>
- デフォルトに戻す<br>
  設定変更前情報を保存していないため、書き換えた後にデフォルト設定に戻す機能がない<br>
  事前にゲーム側で情報を保持しておき、戻すなどゲーム側での実装が必要
- Ctrl/Alt/Shift + Keyの設定<br>
  現段階では用意していません。単一のキーでの動作のみとなります。
- キーの重複チェック<br>
  例えば前進に「W」ジャンプにも「W」が割り当てれてしまいます。<br>
  この場合挙動がおかしくなるため、弾く必要があります。


## Node List
![node_overview](https://user-images.githubusercontent.com/8968076/82068830-7ca86080-970d-11ea-9c9f-145773416d10.png)


## Example
FirstPersonTemplateのJump/Fire/Pause(独自に追加)のKeyboard/GamePadでのRemapping<br>
InputTypeによって書き換え先のキーを変えているため、Gamepadにしている場合にはキーボードが押されても変更されない仕様です<br>
同様にInputTypeがKeyboardの場合にはGamepad側のキーに影響がありません<br>
![Jump](https://user-images.githubusercontent.com/8968076/81720062-d95f0d80-94b8-11ea-930e-d134b7b7712a.png)
