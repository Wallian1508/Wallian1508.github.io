import random
from PIL import Image
import matplotlib.pyplot as plt

data = ["紅綠燈" ,"香蕉" ,"蘋果" ,"摩托車" ,"書本" ,"筆電" ,"飛機" ,"拖鞋", "褲子", "公雞" , "乳牛", "腳踏車", "汽車"]
#所有可能的題目類別(素材名稱)

answer_summoner = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20] #生成答案所用的陣列
option = [0,0,0,0,0,0,0,0,0]  #用來填入選項的空陣列
pass_or_not = 0 #紀錄是否通過

while(pass_or_not == 0):  #主迴圈，沒通過時重複
  question = random.randint(0, 12)    #選定題目
  number_of_answer = random.randint(3,5)    #選定本次題目正確答案的數量
  random.shuffle(answer_summoner) #打亂答案生成器

  for i in range(number_of_answer):   #將答案生成器中對應數量的值放入選項中作為正確答案
    option[i] = answer_summoner[i] + 20 * question - 1  #將答案編碼並存入

  print("選出下列包含 " + data[question] + " 的圖片")   #輸出題幹

  for i in range(number_of_answer, 9):  #生成剩下的選項
    option[i] = random.randint(0, 239)    #生成錯誤選項(不含正確答案)
    if option[i] >= question * 20:     #若答案在正確答案以後
      option[i] += 20               #則往後補一個類別
    for j in range(i):            #檢查是否有重複的選項
      while option[i] == option[j]:       #選項相同時
        option[i] = random.randint(0, 239)
        if option[i] >= question * 20:
          option += 20          #同上重新生成錯誤選項直到不同

  random.shuffle(option)        #打亂選項

  for i in range(9):  #輸出選項
    print(i+1,'.')    #輸出題號
    img = Image.open("/content/drive/MyDrive/project2/material/"+data[(option[i])//20]+"/"+data[(option[i])//20]+"/Image_"+str(option[i]%20+1)+".jpg")
    #解碼並找到檔案位置
    plt.imshow(img)
    plt.show()    #輸出圖片

  correct_answer = str()  #生成空的字串用於紀錄正確答案
  for i in range(9):            #找出正確答案(重複所有選項)
    for j in range(number_of_answer):    #重複正確答案
      if option[i] + 1 == answer_summoner[j] + (question * 20):   #若選項與正確答案相同
        correct_answer += str(i + 1)                    #記錄該選項

  print("請作答，若答案為選項1、2、3，請輸入123")
  answer = input()  #輸入答案

  if answer == correct_answer:  #若答案正確
    pass_or_not = 1         #將已通過紀錄
    print('恭喜通過!!!')
  else:
    print('失敗')