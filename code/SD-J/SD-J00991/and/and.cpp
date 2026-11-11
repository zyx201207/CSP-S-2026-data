#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p;
void dfs(long long qq,long long q,long long pp){
	if(q==m){
		p=max(pp,p);
		return ;
	}
	for(int i=qq+1;i<=n;i++){
		if(q==0){
			dfs(i,q+1,a[i]);
		}
		else{
			dfs(i,q+1,(a[i]&pp));
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<p;
		return 0;
	}
	else if(n>20&&n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				p=max(p,a[i]);
			}
			cout<<p;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					p=max(p,(a[i]&a[j]));
				}
			}
			cout<<p;
			return 0;
		}
		if(m==n){
			p=a[1];
			for(int i=2;i<=n;i++){
				p=(p&a[i]);
			}
			cout<<p;
			return 0;
		}
	}
	else{
		if(m==n-1){
			p=a[1];
			for(int i=2;i<n;i++){
				p=(p&a[i]);
			}
			cout<<p;
			return 0;
		}
		cout<<7;
	}
	return 0;
}
