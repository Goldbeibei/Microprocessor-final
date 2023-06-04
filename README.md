# Microprocessor-final
 微處理機實驗期末專題   

# 主要貢獻
 - 給予主題方向：黃坤成總監
 - 構思主題想法與實行步驟：李杰儒組長(README.md與notion報告書)
 - 實作將四個溫度計程式顯示完成DHTtester2.ino：陳彥杰(v1.0.1)

# 預期目標
 根據環境溫度，當環境溫度高於設定溫度後，自動發射紅外線開啟冷氣，並經由安裝在冷氣出風口的溫度感測器判定冷氣是否開啟，並使用LED顯示冷氣開啟狀態  
 目前使用linkit7697作為主控

# 預期工作
 - 感測多個溫溼度，使用DHT22：陳彥杰(已部分完成)
 - 實現使用紅外線發射器實現訊號的發送：鄒閔丞
 - 可使冷氣接收到訊號後開啟：陳柏睿
 - 顯示冷氣是否開啟狀態指示燈，外接一個LED或使用主板上的
 - 設置一個物理按鍵強制開啟冷氣或關閉：劉子睿

# 未來方向
 - 建立方便觀測數據的網頁端，可能使用node-red之類的網頁服務
 - 在機器上安裝紅外線接收器以記錄冷氣遙控器的紅外線訊號，並用於未來擴增機器使用
 - 使其可在其他開發版上使用，例如arduino或ESP32等等

# 使用材料
 - 主控linkit7697 *1
 - 溫溼度感測DHT22 *4
 - 紅外線發射器1341-K090 *1

# 開發環境
 Arduino 1.8.19(理論上1.8.x都可)
