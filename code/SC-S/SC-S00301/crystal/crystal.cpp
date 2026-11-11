#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long dif[500005];
long long b[500005];
long long dfs(long long i,long long len,long long pow){
	if(i>n){
		return len-1;
	}
	if(pow>m){
		return len-1;
	}
	else{
		return max(dfs(i+1,len+1,pow+dif[i+1]*len),dfs(i+1,1,0));
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
    	dif[i]=a[i]-a[i-1];
	}
	bool pd=1;
	for(long long i=1;i<n;i++){
		if(dif[i]!=dif[i+1]){
			pd=0;
		}
	}
	if(pd){
		for(long long i=1;i<=n+1;i++){
			b[i]=b[i-1]+i;
			if((b[i]*dif[1])>m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<dfs(1,1,0)<<endl;
	return 0;
}
//search is good for me