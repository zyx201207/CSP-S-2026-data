#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i-1]>a[i]){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=2;i<=m;i++){
			b[i]=b[i]+b[i-1];
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2){
					cnt++;
				}
			}
			cout<<n<<" "<<cnt;
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans<<" "<<n;
			return 0;
		}
	}
	if(m==n){
		for(int i=1;i<=m;i++){
			cout<<(m-i+1)<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(i==a[n]){
			b[i]=n;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}