#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
using ll=long long;
int n,m;
int a[500010];
int T;
int b[500010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[n]-a[i];
    }
    ll max2=-1;
    ll ans1=-1,ans2=-1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll cnt=0;
            for(int x=i;x<=j;x++){
                cnt+=b[x]-b[i];
            }
            if(cnt>m)break;
            if(cnt>max2){
                ans1=i;
                ans2=j;
            }
            max2=max(max2,cnt);
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<b[i]<<endl;
    //}
    cout<<max((ll)1,ans2-ans1);
return 0;
}
