# 41343141

作業二
第一題

## 解題說明

實作Polynomial類別(ADT)

### 解題策略

1.建構子
  Add( )
  Mult( )
  Eval( )

2.管理Term陣列( termArray / capacity / terms )

## 程式實作

以下為主要程式碼: 

(coding-frenzy)

```cpp

class Term {
	friend Polynomial;
	friend ostream& operator<<(ostream &output, const Polynomial &Poly);
private:
	int exp;
	float coef;
};

class Polynomial {
private:
	Term* termArray;
	int capacity;
	int terms;
public:
	Polynomial() :capacity(2), terms(0) {
		termArray = new Term[capacity];
	}
	~Polynomial() { delete[] termArray; }
	Polynomial Add(Polynomial b);
	Polynomial Mult(Polynomial b);
	float Eval(float x);
	void newTerm(const float newcoef, const int newexp);

```
(Visual Studio)

```cpp
class Term {
    friend class Polynomial;
private:
    int exp;
    float coef;
};

class Polynomial {
private:
    Term* termArray;
    int capacity;
    int terms;

public:
    Polynomial();
    ~Polynomial();
    Polynomial Add(Polynomial b);
    Polynomial Mult(Polynomial b);
    float Eval(float x);
    void newTerm(const float newcoef, const int newexp);
};

```

## 效能分析

| 函式       | 時間複雜度    | 空間複雜度         |
| -------- | -------- | ------------- |
| `Add()`  | O(m + n) | O(m + n)      |
| `Mult()` | O(m × n) | O(m + n)（或更多） |
| `Eval()` | O(m)     | O(1)          |


## 測試與驗證

### 測試案例

| 第一項 | 第二項 | 輸出結果 |
| - | - | --------- |
| 3 5 2 3 1 7 0 | 2 3 2 -5 0 | 8X^ + 3X^1 + 2X^0 |
| 3 3 4 2 2 -5 0 | 3 -1 3 4 1 -1 0 | 3X^4 + -1X^3 + 2X^2 + 4X^1 + -6X^0 |
| 2 4 3 2 1 | 2 3 3 5 0 | 7X^3 + 2X^1 + 5X^0 |

### 編譯與執行指令

```bash
# 編譯
g++ Source.cpp -o polynomial.exe

# 執行
Polynomial.exe
```

### 結論

1.使用Visual Studio編譯測試會導致多個 Polynomial 共用同一塊記憶體。

2.因此使用Visual Studio更改一些程式在輸入大項數（>10）時能自動擴充記憶體，未發生崩潰。

3.輸入與輸出格式清晰，執行穩定，無記憶體錯誤。

## 申論及開發報告

| 功能                      | 瘋狂程設                             | Visual Studio                                    | 差異說明                               |
| ----------------------- | ------------------------------ | ------------------------------------------- | ---------------------------------- |
| **拷貝建構子**               | ❌ 無                            | ✅ 加入                                        | 保證複製時新建一份 termArray，不共用同一記憶體       |
| **指派運算子 =**             | ❌ 無                            | ✅ 加入                                        | 避免 result = polyA.Add(polyB) 時重複刪除 |
| **newTerm 擴充機制**        | ❌ 沒有 `reserve()`               | ✅ 新增自動擴充                                    | 防止 termArray 滿時寫出界導致 crash         |
| **Add 函式宣告**            | `Polynomial Add(Polynomial b)` | `Polynomial Add(const Polynomial& b) const` | 改成以常量參考傳入，避免多餘複製                   |
| **解構子安全性**              | 可能重複 delete                    | 不會                                        | 因為每個物件都有獨立的記憶體                     |
| **Move semantics (可選)** | ❌ 無                            | ✅ 可加（非必須）                                   | 提升效能，減少不必要複製                       |

-------------------------------------------

作業二
第二題

## 解題說明

編寫 C++ 函數用於計算多項式的加法。

### 解題策略

Polynomial 類別基礎上，
完成兩個功能：

	輸入多項式運算子	operator>>
	輸出多項式運算子	operator<<

利用程式碼做出加法運算。
	
## 程式實作

以下為主要程式碼：

```cpp

istream& operator>>(istream& is, Polynomial& poly) {
//輸入運算子多載
	float coef;
	int exp, n;
	is >> n;
	while (n--) {
		is >> coef >> exp;
		poly.newTerm(coef, exp);
	}
	return is;
}


ostream& operator<<(ostream& out, const Polynomial& p) {
//輸出運算子多載
    if (p.terms == 0) {
        out << "0";
        return out;
    }
    for (int i = 0; i < p.terms; ++i) {
        if (i > 0) out << " + ";
        out << p.termArray[i].coef << "X^" << p.termArray[i].exp;
    }
    return out;
}

```

## 效能分析

| 函式名稱         | 時間複雜度 | 空間複雜度 |
| ------------ | ----- | ----- |
| `operator>>` | O(n)  | O(n)  |
| `operator<<` | O(n)  | O(1)  |

整體C++函式運作

| **時間複雜度** | **O(m + n)** |

| **空間複雜度** | **O(m + n)** |


## 測試與驗證

### 測試案例

| 第一項 | 第二項 | 輸出結果 |
| - | - | --------- |
| 3 5 2 3 1 7 0 | 2 3 2 -5 0 | 8X^ + 3X^1 + 2X^0 |
| 3 3 4 2 2 -5 0 | 3 -1 3 4 1 -1 0 | 3X^4 + -1X^3 + 2X^2 + 4X^1 + -6X^0 |
| 2 4 3 2 1 | 2 3 3 5 0 | 7X^3 + 2X^1 + 5X^0 |

### 編譯與執行指令

```bash
# 編譯
g++ Source.cpp -o polynomial.exe

# 執行
Polynomial.exe
```

### 結論

1.可以輸入不同項數的多項式,每一項的係數跟指數都能正確讀進來並且存起來。
2.輸出的時候格式很清楚,會按照順序印出每一項的係數跟指數。
3.如果是空的多項式(項數是0)的話,程式可以正確的顯示成0。
4.程式執行很穩定,不會有記憶體錯誤或是超出範圍的問題。

## 申論及開發報告

這題要寫一個程式,可以輸入兩個多項式(項數不限制)然後做加法。

### 1. **類別宣告**  

因為要讓運算子可以直接用到類別裡面的私有成員(termArray, terms),
所以operator>>跟operator<<要寫成friend function才行。

### 2. **輸入及輸出**  

用operator>>來讀取多項式有幾項,然後一個一個輸入每一項的係數跟指數。
用之前寫好的newTerm()這個函式把資料加到termArray這個動態陣列裡面。
用operator<<把多項式印出來,印的格式要讓人容易看懂。

### 3. **指數排序+合併策略**

一個一個比較兩個多項式現在這一項的指數大小。
如果指數一樣→把係數加起來,結果放進新的多項式。
如果指數不一樣→把指數比較大的那一項直接加進新多項式。
當其中一個多項式的項都處理完了,就把另一個多項式剩下的項全部加進結果裡面。

## 心得

這次寫多項式加法的程式,一開始覺得蠻複雜的,尤其是要處理不同指數的項要怎麼排序跟合併。不過寫完之後發現其實概念還滿清楚的,就是把兩個多項式一項一項比較,指數一樣就係數相加,不一樣就看誰大就先放誰。用friend function讓運算子可以直接存取私有成員這個方法也學到了,感覺以後寫程式會更方便。整體來說雖然有點難但是學到不少東西。
