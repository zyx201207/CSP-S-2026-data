#include<bits/stdc++.h>
using namespace std;
int g[200009];
bool cmp(int a,int b){
	int q=0,p=0;
	while(a){
		if(a%2==1) q++;
		a/=2;
	}
	while(b){
		if(b%2==1) p++;
		b/=2;
	}
	if(q>p) return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n,cmp);
	int ans=g[1];
	for(int i=2;i<=m;i++){
		ans&=g[i];
	}
	cout<<ans;
	return 0;
}