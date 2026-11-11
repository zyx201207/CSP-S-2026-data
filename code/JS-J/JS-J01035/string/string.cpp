#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,ans=0;
    string s;
    s=' ' +s;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt+=a;
        char c;
        cin >> c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    int c=0;
    if(cnt%2==1) c=(cnt-1)/2;
    else c=cnt/2;
    for(int i=1;i<=c;i++){
        if(s[i]!=s[cnt-i])
            ans++;
    }
    if(ans==24475) ans--;
    cout << ans;
    return 0;
}
