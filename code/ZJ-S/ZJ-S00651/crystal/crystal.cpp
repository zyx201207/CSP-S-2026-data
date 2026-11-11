#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500001];
bool f=true;
bool f2=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=false;
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f2=false;
		}
	}
	if(f){//15pts
		for(int i=1;i<=n;i++){
			int sum=(0+i-1)*i/2;
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}
	else if(f2){//15pts
		for(int i=1;i<=n;i++){
			int sum=(a[i]-a[1]+a[i]-a[i-1])*(i-1)/2;
			if(sum>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}
	else{//45pts
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=n;i>=1;i--){
			int xx=0;
			int mm=m;
			for(int j=i;j>=1;j--){
				if(mm>=a[i]-a[j]){
					mm-=a[i]-a[j];
					xx++;
				}
				else{
					break;
				}
			}
			ans=max(ans,xx);
		}
		cout<<ans;
	}
	
	return 0;
}
