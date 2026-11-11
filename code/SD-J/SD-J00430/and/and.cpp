#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		int ans=0;
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		long long maxx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else{
		int maxx=-1,num;
		for(int i=1;i<=n-m;i++){
			num=a[i];
			for(int j=i+1;j<=i+m-1;j++){
				num=num&a[j];
			}
			maxx=max(num,maxx);
		}
		cout<<maxx;
	}
	return 0;
}
