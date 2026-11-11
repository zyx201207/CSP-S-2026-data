#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans=1,b[500010],cnt,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&p!=a[i]-a[i-1]){
			cnt=1;
		}
		if(i!=1){
			p=a[i]-a[i-1];
		}
	}
	if(cnt==0){
		ll k=m;
		for(int i=n-1;i>=1;i--){
			if(k>=abs(a[n]-a[i])){
				ans++;
				k-=abs(a[n]-a[i]);
			}else{
				break;
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i==1){
				b[i]=1;
				continue;
			}else if(a[i]==a[i-1]){
				b[i]=b[i-1]+1;
			}else{
				ll k=m;
				b[i]=1;
				for(int j=i-1;j>=1;j--){
					if(k>=abs(a[i]-a[j])){
						b[i]++;
						k-=abs(a[i]-a[j]);
					}else{
						break;
					}
				}
			}
			ans=max(ans,b[i]);
		}
		cout<<ans;
	}
	return 0;
}
