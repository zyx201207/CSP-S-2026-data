#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],maxn=1,ans,_tm,d=-1;
bool f=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(d==-1) d=a[i]-a[i-1];
        else{
            if(a[i]-a[i-1]!=d){
                f=0;
                break;
            }
        }
    }
    if(f==0){
        for(long long i=1;i<=n;i++){
            ans=0;
            _tm=0;
            for(long long j=i;j>=1;j--){
                _tm+=a[i]-a[j];
                if(_tm>m) break;
                ans++;
            }
            maxn=max(ans,maxn);
        }
        cout<<maxn;
        return 0;
    }
    else{
        for(long long i=n;i>=1;i--){
            if(d*i*(i-1)<=2*m){
                cout<<i;
                return 0;
            }
        }
        cout<<1;
    }
}
