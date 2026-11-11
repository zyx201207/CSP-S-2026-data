#include<bits/stdc++.h>
using namespace std;
string a;
int m,t,ans=0,b=0;
long long cnt;
char n;
int main(){
    a+='0';
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>m>>n;
        cnt+=m;
        for(int j=1;j<=m;j++)
            a+=n;
    }
    for(int i=b+1;i<=cnt/2;i++){
        if(a[i]!=a[cnt+1-i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
