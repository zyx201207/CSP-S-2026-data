#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300000],vis[300000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
	cin>>a[i];
	}
	for(long long i=31;i>=0;i--){
		long long j=(1<<i),s=0;
		for(int k=1;k<=n;k++){
			if(!vis[k]&&(a[k]&j))
			s++;
		}
		if(s>=m){
		ans+=j;
		for(int k=1;k<=n;k++){
			if(!(a[k]&j))vis[k]=1;
		}
	}
	}
	cout<<ans;
	return 0;
} 
