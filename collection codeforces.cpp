//CodeForces 2267B. Fashionable Array Version 1
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> cnt;
        for(int j=0; j<n;  j++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        vt nums;
        for(auto& p : cnt){
            nums.push_back(p.first);
        }
        sort(nums.rbegin(), nums.rend());
        vt ans;
        for(int x=1; (int)ans.size()<n; x++){
            for(int c:nums){
                if (cnt[c] >= x){
                    ans.push_back(c);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << ans[i] << " \n"[i==n-1];
        }
    }
    return 0;
}

//CodeForces 2257B.  Gigantomachy
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vt;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
    ll n,m;
    cin >> n >> m;
    vt a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vt b(m);
    for(ll i=0;i<m;i++){
        cin >> b[i];
    }
    ll cnta=0;
    ll cntb=0;
    for (ll i=1;i<a.size();i++){
        cnta+=a[i-1]-a[i]+1;
    }
    for (ll i=1;i<b.size();i++){
        cntb+=b[i-1]-b[i]+1;
    }
    if (cnta+a[a.size()-1]>=cntb+b[b.size()-1]){
        cout << 1 << "\n";
    }
    else{
        cout << 2 << "\n";
    }
}
    return 0;
}

//CodeForces
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vt;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vt p(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        vt idx1;
        vt idx2;
        for(int j=0;j<n;j++){
            if(p[j]==-1){
                idx1.push_back(j);
            }
            if(p[j]==1){
                idx2.push_back(j);
            }
        }
        if(idx1.size())
        if(idx2.size()==0){
            for(int& q:p){
            if(q==-1){
                q=0;
            }
        }
        for(int i=0;i<n;i++){
            cout << p[i] << end" ";
        }
        }
        if(idx2.size()==1){

        }
        if(idx1[0]<idx2[0]){
            p[idx1[0]]=1;
        }
        if(idx1[idx1.size()-1]>idx2[idx2.size()-1]){
            p[idx1[idx.size()-1]]=1;
        }
        for(int& q:p){
            if(q==-1){
                q=0;
            }
        }
        for(int i=0;i<n;i++){
            cout << p[i] << " ";
        }
    }
    return 0;
}

//妈个比的TLE
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vt;
int main(){
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        char x;
        cin >> n >> x;
        string s;
        cin >> s;
        int cnt=0;
        for(int i=0;i<n/2+1;i++){
            if(s[i]!=s[n-1-i]){
                cnt+=2;
            }
            if(x==s[i] || x==s[n-1-i]){
                cnt--;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
//version 1
#include <vector>
#include <iostream>
using namespace std;
typedef vector <int> vt;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vt p(n);
        for(int i =0;i<n;i++) cin >> p[i];
        int max_num=0;
        for(int i=1;i<=m;i++){
            int cnt=0;
            int doub=0;
            for(int j=0;j<n;j++){
                if(p[j]>=i) cnt++;
                if(p[j]==2*i) doub++;
            }
            max_num=max(max_num,cnt+doub);
        }
        cout << max_num << "\n";
    }
    return 0;
}
//version 2
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
            cin >> p[i];
            p[i]++;
        }
        vt suf(m+2,0);
        //这个优化绝了
        for (int i = m; i >= 1; i--) {
            suf[i] = suf[i + 1] + p[i];
        }
        int ans = 0;
        for (int L = 1; L <= m; L++) {
            int cnt = suf[L];                      // 长度 >= L 的个数
            int extra = (2 * L <= m) ? freq[2 * L] : 0; // 恰好 2L 的额外一个，这里用了三目运算符。
            ans = max(ans, cnt + extra);
        }
        cout << ans << "\n";
    }
    return 0;
}