#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,p,ans;
void f(long long s,long long x){
	if(x==m){
		ans=max(ans,p);
		//cout<<p<<" ";
		return;
	}
	for(int i=s;i<=n;i++){
		p=p&a[i];
		f(i+1,x+1);
		p=a[i];
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	f(1,0);
	cout<<ans;
	return 0;
}
