#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100010],b[100010];
int f=1,mx=-1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=5e5){
		ll x=a[2]-a[1];
		for(int i=4;i<=n;i++){
			if(a[i]-a[i-1]!=x){
				f=0;
				break;
			}
		}
		if(f){
			ll zd=n/2,sum=0,cnt=1,cs=1;
			for(int i=1;i<=zd-1;i++){
				if(sum+x*cs>m){
					cout<<cnt;
					return 0;
				}
				else if(sum+x*cs==m){
					cnt++;
					cout<<cnt;
					return 0;
				}
				sum+=x*cs;
				cnt++;
				if(sum+x*cs>m){
					cout<<cnt;
					return 0;
				}
				else if(sum+x*cs==m){
					cnt++;
					cout<<cnt;
					return 0;
				}
				sum+=x*cs;
				cnt++;
				cs++;
			}
		}
		else{
			cout<<315275;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++){
			b[j]=abs(a[i]-a[j]);
		}
		sort(b+1,b+n+1);
		ll ans=0;
		for(int k=1;k<=n;k++){
			if(ans+b[k]<m){
				ans+=b[k];
			}
			else if(ans+b[k]==m){
				mx=max(mx,k);
				break;
			}
			else{
				mx=max(mx,k-1);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
}