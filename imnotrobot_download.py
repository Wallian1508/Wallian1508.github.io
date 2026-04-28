!pip install bing-image-downloader==1.0.4    #下載bing_image_downloader
from bing_image_downloader import downloader
import os

data = ["紅綠燈" ,"香蕉" ,"蘋果" ,"摩托車" ,"書本" ,"筆電" ,"飛機" ,"拖鞋", "褲子", "公雞" , "乳牛", "腳踏車", "汽車"]
#所有可能的題目類別(素材名稱)

for i in data:  #下載圖片
  downloader.download(
    i,                            #圖片名稱
    limit = 20,                       #數量最多為20
    output_dir = '/drive/MyDrive/project2/material/' + i, #儲存圖片的位置
    adult_filter_off = 1,                   #過濾成人圖片(?
    force_replace = 1,                    #覆蓋已存在資料夾
  )
