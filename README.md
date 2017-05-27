# はじめに
 生産や加工のための装置の頭脳である、PLCからarduinoを使用して情報を拾うために作成したプログラムです。
# 詳細
　出力端子での通電を検知します。
 http://www.geocities.jp/zattouka/GarageHouse/micon/circuit/pullup.htm
## 入力でのノイズへの対応
　実際に使用すると入力のノイズを拾って意図するタイミングを拾うことができないので、フィルターを入れた。
 http://www.cqpub.co.jp/hanbai/books/34/34451/34451_1SYO.pdf
 http://ehbtj.com/electronics/sensor-digital-filter/
## チャタリング防止
　http://n.mtng.org/ele/arduino/switches.html
