#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5e5+5;
ll n,m,a[N],sum[N];
bool check(int p){
    ll need=(p-1)*a[p];
    ll have=sum[p];
    if(need-have>m) return 0;
    return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool A=1,B=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) A=0;
        if(i<=2) continue;
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) B=0;
    }
    if(A){
        for(int i=n;i>=1;i--){
             ll need=(i-1)*i;
             ll have=i*(i-1)/2.0;
             //printf("i = %d, need = %d, have = %d, m = %d\n",i,need,have,m);
             if(m>=need-have){
                cout<<i<<endl;
                break;
             }
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(B){
        for(int i=n;i>=1;i--){
            ll need=a[i]*(i-1);
            ll have=sum[i-1];
            //printf("i = %d, need = %d, have = %d, m = %d\n",i,need,have,m);
            if(m>=need-have){
                cout<<i<<endl;
                break;
            }
        }
        return 0;
    }
    int l=1,r=n,mid,ans;
    while(l<r){
        mid=(l+r)/2;
        //cerr<<l<<' '<<r<<' '<<mid<<' '<<ans<<endl;
        if(check(mid)){
        	ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
