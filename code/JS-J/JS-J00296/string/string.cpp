#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int MAXN=200005;
int num[MAXN],n,ans;
char x[MAXN];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i]>>x[i];
    int i=1,j=n;
    while(i<j){
        if(x[i]!=x[j]) ans+=min(num[i],num[j]);
        if(num[i]>num[j]) num[i]-=num[j],j--;
        else if(num[i]<num[j]) num[j]-=num[i],i++;
        else i++,j--;
        //cout<<i<<" "<<j<<endl;
        //cout<<num[i]<<" "<<num[j]<<endl;
    }
    cout<<ans;
    return 0;
}

//id:JS-J00296
//This is the code of string.
//100 pts
//All samples correct.
//Last modified on Oct.31st 09:30
//password:Trick||Treat!
