#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0,ans=0,a[200005];
char c[200005];
bool flag=false;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        a[i]+=a[i-1];
    }
    if(cnt%2==1)
        flag=true;
    long long cnt2=cnt/2;
    for(long long i=cnt2+1+flag;i<=cnt;i++){
        long long j=lower_bound(a+1,a+n+1,i)-a;
        long long newi=cnt+1-i;
        long long jj=lower_bound(a+1,a+n+1,newi)-a;
        if(c[j]!=c[jj])
            ans++;
    }
    cout<<ans;
    return 0;
}