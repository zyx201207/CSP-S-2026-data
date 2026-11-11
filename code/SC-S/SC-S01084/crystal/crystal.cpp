#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000];
int b[1000000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=0;
	bool f=true,f1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=false;
		}
	}
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			f1=false;
			break;
		} 
	}
	if(f){
		for(int i=2;i<=n;i++){
			if((i*i-i)/2<=m){
				ans=i;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(f1){
		for(int i=2;i<=n;i++){
			int c1=(a[i]-a[1])/c;
			if((c1*c1+c1)/2*c<=m){
				ans=i;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=1e10;
		}
		int sum=0,t=0;
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]){
				b[j]=a[i]-a[j];
			}
			else if(a[j]==a[i]){
				t++;
			}
		}
		sort(b+1,b+1+n);
		for(int j=1;j<=n;j++){
			sum+=b[j];
			if(sum>m){
				break;
			}
			t++;
		}
		ans=max(ans,t);
	}
	cout<<ans;
}