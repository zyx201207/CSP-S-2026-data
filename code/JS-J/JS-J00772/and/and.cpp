#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[222222],ans,p;
string div(long long x){
    string s="";
    while(x!=0){
        s+=(x%2+'0');
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
bool cmp(long long x,long long y){
    string s=div(x),t=div(y);
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.size();i++){
        cnt1+=(s[i]=='1');
    }
    for(int i=0;i<t.size();i++){
        cnt2+=(t[i]=='1');
    }
    if(cnt1==cnt2)
        return s>t;
    return cnt1>cnt2;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    printf("%lld",ans);
}
