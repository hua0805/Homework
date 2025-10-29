# 41343141

作業二
第一題
## 解題說明

本題要求設計一個多項式類別的類別介面與基本運算功能。

### 解題策略

1.定義 Term 儲存係數與指數，Polynomial 用動態陣列管理多項式項目。
2.以 operator+、operator* 完成多項式加法與乘法，用 Eval() 計算多項式值。

## 程式實作

```cpp


```

## 效能分析

1. 時間複雜度：程式的時間複雜度為 Eval:O(t) Add:O(n+m) Mult:O((nm)^2)。
2.空間複雜度：空間複雜度為 Eval:O(1) Add:O(n+m) Mult:O((nm))。

## 測試與驗證

### 測試案例

<img width="392" height="156" alt="image" src="https://github.com/user-attachments/assets/a444156d-fe6d-4ae9-b4b7-18cc2f015b3b" />

<img width="595" height="156" alt="image" src="https://github.com/user-attachments/assets/c40ff859-b5e0-459e-9803-2ebb83c43db9" />

<img width="432" height="152" alt="image" src="https://github.com/user-attachments/assets/d5562730-7d0b-4ba9-88d1-d3571196fa34" />

### 編譯與執行指令

```shell
$ g++ -std=c++17 -O2 -Wall Homework2.cpp -o hw2.exe
$ .\hw2.exe=
```

### 結論

1.程式能正確計算當exp跟coef個別是多少時的答案。
2.在exp是0或負數的情況下，程式是否正確，符合設計預期。
## 申論及開發報告

### 選擇friend的原因
在本程式中，使用friend來寫這串code的主要原因如下：

1.允許內部直接訪問私有資料 在 Polynomial 的成員函式裡（例如 Eval()、normalize()）可以直接寫：
s += termArray[i].coef * pow(x, termArray[i].exp); 這是可行的，因為 Term 對 Polynomial 是 friend;沒有這行 friend 的話則會出現error。

2.好處
Polynomial 是唯一能操作 Term 內部的類別。 外部（例如 main()）不能直接動 coef 或 exp，防止亂改資料。

3.沒有使用friend的情況
因Term的私有資料無法被Polynomial使用，所以coef和exp會是pritave。 程式碼會變得更長一串、更消耗效能、記憶體之類的。 因為少了friend就代表不能直接存取，需要跑好幾個流程才可以存取。 所以程式執行的時間一旦長起來，消耗的東西就會增長。

   ```
### 心得
在上學期就有學習過C++中的*friend*，但在課堂實際使用卻很少，這次的功課難得出現可以使用*friend*的程式，因為這次的程式碼很長一串，我當時就在講要怎麼把效能提升上去，不要吃這麼多記憶體，突然就想到了之前學過的*friend*而且剛好，這段程式碼又很常去抓函式裡面的數值或變數。
這次使用*friend*讓我對這個程式有更深入的理解，像是*friend*常使用的方式: *friend class X*
 *friend 函式宣告*，而且我覺得*friend*這個程式很有趣，跟他的名字一樣，是朋友，朋友之間可以互相存取，但朋友的朋友不能存取，很像是雙方的小祕密一樣。
 這次使用*friend*讓我知道他的優缺點，優點是可以緊密合作、保持封裝、參數不容易被修改、被保護得很好。缺點是當濫用了*friend*會讓類別之間相似度過高，很容易改了一邊參數另外一邊也一起更動了，可維護性和測試性會下降，因為太多朋友了會導致邊界模糊。
    PowerSetRecursive(S, index + 1, subset);
    subset.pop_back();
   }
   ```
