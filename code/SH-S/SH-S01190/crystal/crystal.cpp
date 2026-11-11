#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll c[5005][5005];
bool flag=1;
int f;
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	f=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
        if(a[i]-a[i-1]!=f){
            flag=0;
        }
	}
	if(flag){
        for(ll i=1;i<=n;i++){
            if(((i*(i-1))/2)*f<=m){
                ans=i;
            }
        }
        cout<<ans;
        return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c[i][j]=a[j]-a[i];
		}
	}
	for(int i=n;i>=1;i--){
		ll sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=c[j][i];
			if(sum<=m){
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
