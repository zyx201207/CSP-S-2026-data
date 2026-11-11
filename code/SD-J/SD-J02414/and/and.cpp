#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],s[31];
bool cmp(int x,int y){
	return x>y;
}
int solve(int kn,int kw){
	for(int i=0;i<30;i++)s[i]=0;
	for(int i=1;i<=kn;i++){
		int k=a[i];
		int j=0;
		while(k){
			s[j]+=(k&1);
			k/=2;
			j++;
		}
	}
	int w=kw-1;
	while(s[w]<m && w>=0)w--;
	if(w==0)return 1;
	if(w<0)return 0;
	int km=0;
	int kmod=pow(2,w);
	for(int i=1;i<=kn;i++){
		if((a[i]>>w)&1)a[++km]=a[i]%kmod;
	}
	//cout<<km<<' ';
	//for(int i=1;i<=km;i++)cout<<a[i]<<' ';
	//cout<<kmod<<'\n';
	return kmod+solve(km,w);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==0){
		cout<<0;
		return;
	} 
	cout<<solve(n,30);
	return 0;
}
