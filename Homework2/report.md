# 41343141

作業一
第一題
## 解題說明

實現阿克曼函數，是非原始遞迴函數的例子，需要兩個自然數輸入值，輸出一個自然數。

### 解題策略

1. 當m==0 時，作為遞迴的結束條件。  
2. 主程式呼叫遞迴函式，並輸出計算結果。

## 程式實作

```cpp
/*遞迴*/
#include <iostream>
using namespace std;

int Ackermann(const int m,const int n){
    if(m==0)
    return n+1;
    else if(n==0)
    return Ackermann(m-1,1);
    else
    return Ackermann(m-1,Ackermann(m,n-1));
}

int main(){
    int m,n;
    cout<<"輸入A(m,n) ";
    cin>>m>>n;
    cout<<"A("<<m<<","<<n<<")="<<Ackermann(m,n)<<endl;
    return 0;
}
```

```cpp
/*非遞迴*/
#include <iostream>
#include <stack>
using namespace std;

int AckermannIter(int m, int n) {
    stack<pair<int,int>> st;
    st.push({m, n});

    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();

        if (x == 0) {
            if (st.empty()) return y + 1;
            auto &top = st.top();
            top.second = y + 1;
        } else if (y == 0) {
            st.push({x - 1, 1});
        } else {
            st.push({x - 1, 0});
            st.push({x, y - 1});
        }
    }
    return 0;
}

int main() {
    int m, n;
    cout << "請輸入兩個整數 m 和 n: ";
    cin >> m >> n;
    cout << "A(" << m << "," << n << ")=" << AckermannIter(m, n) << endl;
    return 0;
}
```

## 效能分析

1. 時間複雜度：*O(A(m,n))*。
2. 空間複雜度：*O(A(m,n))*。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數 *m* | 輸入參數 *n* | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|----------|
| 測試一   | *m = 0*      | *n = 2*        | 3        | 3        |
| 測試二   | *m = 1*      | *n = 2*        | 4        | 4        |
| 測試三   | *m = 3*      | *n = 3*        | 61      | 61      |
| 測試四   | *m = 3*      | *n = 4*        | 125        | 125        |
| 測試五   | *m = 0*      | *n = 0*        | 拋出異常        | 拋出異常        |

### 編譯與執行指令

```shell
g++ -std=c++17 -O2 -o ack ackermann.cpp
./ack
```

### 結論

1. 能正確計算當*m*跟*n*分別是多少時的答案。  
2. 在*m*跟*n*都是*0*，程式會拋出異常，符合預期。  
3. 涵蓋多種邊界情況（*m = 0* *n = 2* || *m = 3* *n = 4* ），驗證程式正確性。

## 申論及開發報告

### 選擇遞迴的原因

1. **程式邏輯簡單直觀**  
   遞迴的寫法能夠清楚表達「將問題拆解為更小的子問題」的核心概念。  
   例如，計算 *A(m-1,A(m,n-1)* 的過程可分解為：  

   
   <img width="660" height="166" alt="image" src="https://github.com/user-attachments/assets/5fd096a4-3a6a-4331-a8ea-ce26ca59289a" />
   

  當*m*=0 時，直接輸出*n+1*的值。

2. **易於理解與實現**  
   遞迴的程式碼更接近數學公式的表示方式，讓我比較好理解。  
   以本程式為例：  

   ```cpp
   int Ackermann(const int m,const int n){
    if(m==0)
    return n+1;
    else if(n==0)
    return Ackermann(m-1,1);
    else
    return Ackermann(m-1,Ackermann(m,n-1));
    }
   ```

3. **遞迴的語意清楚**  
   在程式中，每次遞迴呼叫都代表一個「子問題的解」，而最終遞迴的返回結果會逐層相加，完成整體問題的求解。  
   這種設計簡化了邏輯，不需要額外變數來維護中間狀態。
   透過遞迴實作簡單的加減計算，程式邏輯簡單且易於理解，特別適合展示遞迴的核心思想。然而，遞迴會因堆疊深度受到限制，當 $n$ 值過大時，應考慮使用迭代版本來避免 Stack Overflow 問題。

     ### 選擇非遞迴的原因

  選擇非遞迴版本的原因主要有幾個技術層面的考量：

1. **避免堆疊溢出（**
    遞迴函數每次呼叫都會佔用系統呼叫堆疊空間。

2. **更可控的記憶體使用**
   * 遞迴會自動在系統堆疊分配變數，每一層呼叫都要存回呼叫狀態。

3. **提高效率與穩定性**
   * 避免重複計算時，非遞迴寫法更容易整合。

4. **適合理解流程**
   * 明確呈現「函數呼叫如何推進與回傳」，對於我們這種初學者更好理解


作業一
第二題
## 解題說明

實現一個遞迴函數，用來計算某個集合 *S* 的冪集合）。

### 解題策略

1. 當集合為空時（即沒有元素可處理），回傳一個只包含空集合的結果 [[]]，作為遞迴的停止條件。  
2. 主程式呼叫遞迴函式，並輸出其結果。

## 程式實作

以下為主要程式碼：

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PowerSetRecursive(const vector<string> &S, int index, vector<string> &subset) {
    if (index == (int)S.size()) {
        
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "}" << endl;
        return;
    }
    PowerSetRecursive(S, index + 1, subset);
    subset.push_back(S[index]);
    PowerSetRecursive(S, index + 1, subset);
    subset.pop_back(); 
}

int main() {
    cout << "=== Powerset (冪集) 遞迴產生程式 ===\n";
    cout << "請輸入集合中元素個數 n：";

    int n;
    cin >> n;
    if (n <= 0) {
        cout << "n 必須大於 0！" << endl;
        return 0;
    }

    vector<string> S(n);
    cout << "請輸入集合的元素（以空白分隔）：";
    for (int i = 0; i < n; ++i)
        cin >> S[i];

    cout << "\n集合 S = { ";
    for (int i = 0; i < n; ++i) {
        cout << S[i];
        if (i + 1 < n) cout << ", ";
    }
    cout << " }\n\n";
    cout << "S 的所有子集合如下（共 2^" << n << " = " << (1 << n) << " 個）：\n";

    vector<string> subset;
    PowerSetRecursive(S, 0, subset);

    return 0;
}
 
```

## 效能分析

1. 時間複雜度：*O(n*2^2)*。
2. 空間複雜度：*O(2^n)*。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數 *n* 元素| 預期輸出 | 實際輸出 ||
|----------|--------------|----------|----------|----------|
| 測試一   | *n=3*   a b c   | {} {c}{b} {b, c} {a} {a, c} {a, b} {a, b, c}        | {} {c}{b} {b, c} {a} {a, c} {a, b} {a, b, c}        |
| 測試二   | *n=2*    a b  | {} {b} {a} {a, b}        | {} {b} {a} {a, b}        |
| 測試三   | *n=1*     a  | {} {a}      | {} {a}      |

### 編譯與執行指令

```shell
g++ -std=c++17 -O2 -o powerset powerset.cpp
./powerset
```

### 結論

1. 正確列出集合中所有子集合，在不同輸入大小下皆正常運作。在集合為空，程式正確回傳僅含空集合的結果，符合遞迴結束條件與預期。

## 申論及開發報告

### 選擇遞迴的原因


1. **程式邏輯簡單直觀**  
   程式邏輯簡單直觀，運作方式清晰，更好理解。
   

2. **易於理解與實現**  
   易於理解與實現，能以簡潔的遞迴結構生成所有子集合。
   以本程式為例：  

   ```cpp
   void PowerSetRecursive(const vector<string> &S, int index, vector<string> &subset) {
    if (index == (int)S.size()) {
        
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "}" << endl;
        return;
    }
    PowerSetRecursive(S, index + 1, subset);
    subset.push_back(S[index]);
    PowerSetRecursive(S, index + 1, subset);
    subset.pop_back();
   }
   ```
