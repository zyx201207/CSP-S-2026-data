#include<bits/stdc++.h>
using namespace std;
int n,a[200001],ans0,ans1=INT_MAX,m;
void p(int k,int x,int cur){
	if(k>n){
		if(x!=m)return;
		ans0=max(ans0,cur);
		return;
	}
	p(k+1,x+1,cur&a[k]);
	p(k+1,x,cur);
}
unordered_set<int>vis;
bool check(){
	for(int i=1;i<=n;i++){
		if(vis.find(a[i])==vis.end()){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans1&=a[i];
	}
	for(int i=0;i<=30;i++)vis.insert((1<<i)-1);
	if(n==m){
		cout<<ans1;
	}else if(m==1){
		int x=0;
		for(int i=1;i<=n;i++)x=max(x,a[i]);
		cout<<x;
	}else if(m==2&&n<=2000){
		int cur=0,mx=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				cur=a[l]&a[r];
				mx=max(mx,a[l]&a[r]);
			}
		}
		cout<<mx;
	}else if(n<=20){
		p(1,0,INT_MAX);
		cout<<ans0;
	}else if(check()){
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else{
		int ans=INT_MAX;
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		for(int i=1;i<=m;i++)ans&=a[i];
		cout<<ans;
	}
	return 0;
}