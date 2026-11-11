#include<bits/stdc++.h>
using namespace std;
int g[200009];
int n,m;
int low(int x){
	int cnt=0;
	if(x==0) return 0;
	while(x!=0){
		x&(x-1);
		cnt++;
	}
	return cnt;
}
bool cmp(int a,int b){
	if(low(a)==low(b)){
		return a<b;
	}
	return low(a)>low(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	sort(g+1,g+1+n,cmp);
	for(int i=1;i<=m-1;i++){
		g[1]=g[1]&g[i+1];
	}
	cout<<g[1]<<endl;
	return 0;
}
