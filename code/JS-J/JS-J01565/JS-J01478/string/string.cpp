#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
char ch[maxn];
int n,p1,p2,tmp1,tmp2,ans,a[maxn];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>ch[i];
    p1=tmp1=1;p2=n;tmp2=a[n];
    while(p1<=p2){
        if(tmp1>a[p1]){
            p1++;
            tmp1=1;
        }
        if(tmp2==0){
            p2--;
            tmp2=a[p2];
        }
        int k=min(a[p1]-tmp1+1,tmp2);
        if(ch[p1]!=ch[p2])
            ans+=k;
        tmp1+=k;tmp2-=k;
        if(p1==p2 || p1==p2-1)
            break;
    }
    cout<<ans<<"\n";
    return 0;
}
