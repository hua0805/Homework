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
