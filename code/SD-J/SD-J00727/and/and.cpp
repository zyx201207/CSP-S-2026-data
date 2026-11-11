#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long b=0;
	long long maxx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b=a[1];
		}else{
			b=b&a[i];
		}
		maxx=max(a[i],maxx);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==n){
		cout<<b;
		return 0;
	}else if(m==2){
		maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}else{
		sort(a+1,a+n+1);
		maxx=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}
	return 0;
}
