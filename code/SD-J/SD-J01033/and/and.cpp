#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
long long a[N];
long long b[N];
int y[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int o=a[i]&a[j];
				if(o>maxx) maxx=o;
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<0;
	return 0;
} 
