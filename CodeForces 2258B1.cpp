//卡点：1.三目运算符可以直接进行条件筛选，类似于lambda。2.line 20-22通过dp优化求和方法，因为各个数字本身就有包含关系。 3.输入时就用数组代替哈希表使用。使用时注意不能按原来那样输入
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef vector <int> vt;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vt p(m+1,0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            p[x]++;
        }
        vt suf(m+2,0);
        //这个优化绝了
        for (int i = m; i >= 1; i--) {
            suf[i] = suf[i + 1] + p[i];
        }
        int ans = 0;
        for (int L = 1; L <= m; L++) {
            int cnt = suf[L];                      // 长度 >= L 的个数
            int extra = (2 * L <= m) ? p[2 * L] : 0; // 恰好 2L 的额外一个，这里用了三目运算符。
            ans = max(ans, cnt + extra);
        }
        cout << ans << "\n";
    }
    return 0;
}