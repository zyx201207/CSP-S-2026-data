#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int ans;
int a[N];
int res;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    s=" "+s;
    for(int i=1;i<=n;i++){
             cin>>a[i];
            char c;
            cin>>c;
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
        ans+=a[i];
    }
    //cout<<s;
    if(ans%2==0){
        if(s[ans/2]!=s[ans/2+1]){
            res++;
        }
        for(int i=1;i<=ans/2-1;i++){
            if(s[i]!=s[ans-i+1]){
                res++;
            }
        }
        cout<<res;
    }
    else{
        for(int i=1;i<=ans/2;i++){
            if(s[i]!=s[ans-i+1]){
                res++;
                //cout<<i;
            }
        }
        cout<<res;
    }
    return 0;
}
