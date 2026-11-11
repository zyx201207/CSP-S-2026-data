#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ll n;
    cin>>n;
    char ch[200010];
    ll m,cnt=0;
    char c;
    for(int i=1;i<=n;i++){
        cin>>m>>c;
        for(int j=1;j<=m;j++){
            cnt++;
            ch[cnt]=c;
        }
    }
    ll l=1,r=cnt,ans=0;
    while(l<=r){
        if(ch[l]==ch[r]){
            l++;
            r--;
        }else{
            ans++;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}


