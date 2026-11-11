#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0,maxx=0;
void pd(int x,int k,int s){
	if(x>n) return;
	if(k>=m){
		maxx=max(maxx,s);
		return;
	}
	for(int i=x+1;i<=n;i++){
		pd(i,k+1,s&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=2;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=a[i];
		pd(i,1,a[i]);
		
	}
	cout<<maxx;
	return 0;
}
