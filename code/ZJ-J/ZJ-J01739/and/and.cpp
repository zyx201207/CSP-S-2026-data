#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
int a[200005];
bool b[200005];
void dfs(int s,long long p){
	if(s==1){
		ans=max(ans,p);
		return;
	}
	for(int i=0;i<n;i++){
		if(b[i]==false){
			b[i]=true;
			dfs(s-1,p&a[i]);
			b[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=true;
		dfs(m,a[i]);
		b[i]=false;
	}
	cout<<ans<<endl;
	return 0;
}
