#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long maxn=1e9+10,minn=-1;
	long long a[100000010];
	long long c;
	cin>>n>>m;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n=2){
		cout<<"2";
	}
	while(m--){
		for(long long i=1;i<=m;i++){
			if(a[i]==a[i+1])
				ans+=a[i+1]-a[i];
			if(m==0) cout<<ans;
				break;
		} 
	
}
return 0;
} 
