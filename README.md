Proje: XOX Oyunu
Kullanılan Donanımlar: 
•	Arduino Uno
•	128x64 Oled Ekran
•	Encoder
•	Buton
•	Jumper Kablolar
•	220 OHM Direnç

Proje Özeti: 
	XOX oyunu bilgisayara karşı ve 1v1 olmak üzere iki şekilde oynana bilmektedir.
•	Bilgisayar:
o	Kullanıcı X Bilgisayar O olarak oynamaktadır.
o	Bilgisayar ilk hamlesini rastgele oynamaktadır.
o	Bilgisayar ikinci hamlesinde eğer X’in 3lü yapıp oyunu bitirme ihtimali var ise onu engellemektedir.
o	Bilgisayar 3. hamle ve sonrasında öncelik olarak kendisinin üçlü yapıp yapamama durumuna bakmaktadır.
o	Eğer üçlü yapabiliyor ise oyunu bitirmekte yapamıyor ise X’in üçlü yapmasını engellemektedir.
•	1v1:
o	Kullanıcı hangi kutunun içine X yada O çizeceğini seçebilmesi için encoder her döndürüldüğünde “-” işaretinin yeri bir sağdaki kutuya geçmektedir. Eğer kutu dolu ise bir sonraki kutuya kadar encoderın çevrilmesi gerekmektedir. 
o	Oyun ilk olarak X ile başlar. 
o	Seçimler buton ile gerçekleşmektedir ve her seçimden sonra sıra X’de ise O’ya, O’da ise X’e geçmektedir.
o	Oyun biri kazanana kadar yada tüm hazneler dolana kadar devam etmektedir.
o	Oyun bittikten sonra 1sn beklenmekte ve daha sonra “Oyun Bitti..” yazısı ekrana yazdırılmaktadır.
