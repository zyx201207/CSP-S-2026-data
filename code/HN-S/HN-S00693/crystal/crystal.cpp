#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
int a[1000010];
int s[1000010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0,f1=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			f1=1;
		}
	}
	if(f==0){
		int t=0;
		for(int i=1; i<=n; i++){
			if(t+i<=m){
				t+=i;
				ans++;
			}
		}
		cout<<ans;
	}else if(f1==0){
		int t=a[2]-a[1];
		m/=t;
		cout<<m;
	}else{
		for(int i=1; i<=n; i++){
			s[i]=s[i-1]+a[i];
		}
		for(int l=1; l<=n; l++){
			for(int i=1; i+l-1<=n; i++){
				int j=i+l-1;
				int t=l*a[j];
				int t1=t-(s[j]-s[i-1]);
				if(t1<=m){
					ans=max(ans,l);
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
