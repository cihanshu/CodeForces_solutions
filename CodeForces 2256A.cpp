#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans=0;
        int m=max(max(a,b),c);
        int q=min(min(a,b),c);
       int n = a + b + c - m - q;  
        if(m-q<=n){
            ans=m-q;
        }
        else{
            ans=n;
        }
        cout << ans <<"\n";
    }
    return 0;
}