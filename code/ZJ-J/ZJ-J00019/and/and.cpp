#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],q[200001],h[200001],c[200001],maxq;
void dfs(int i,int g){
	if(g==m){
		long long qq=c[1];
		for(int i=2;i<=g;i++){
			qq&=c[i];
		}
		maxq=max(maxq,qq);
		return;
	}
	if(i>n){
		return;
	}
	g++;
	c[g]=a[i];
	dfs(i+1,g);
	c[g]=0;
	g--;
	dfs(i+1,g);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1){
				q[i]=a[i];
			}
			else{
				q[i]=q[i-1]&a[i];
			}
		}
		for(int i=n;i>=1;i--){
			if(i==n){
				h[i]=h[i];
			}
			else{
				h[i]=h[i+1]&a[i];
			}
		}
		maxq=max(h[2],q[n-1]);
		for(int i=2;i<n;i++){
			maxq=max(maxq,h[i+1]&q[i-1]);
		}
		cout<<maxq;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				maxq=a[i];
			}
			else{
				maxq&=a[i];
			}
		}
		cout<<maxq;
		return 0;
	}
	if(n<=20){
		dfs(1,0);
		cout<<maxq;
		return 0;
	}
	if(m==2){
		maxq=a[1]&a[2];
		for(int i=2;i<n;i++){
			maxq=max(maxq,a[i]&a[i+1]);
		}
		cout<<maxq;
		return 0;
	}
	for(int i=n;i>=n-m+1;i--){
		maxq&=a[i];
	}
	cout<<maxq;
	return 0;
}
