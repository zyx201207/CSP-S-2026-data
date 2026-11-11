#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
struct obj{
	int x,c;
} g[N];
int fun(int x){
	int cnt=0;
	for(int i=0;i<=30;i++){
		if(x&(1<<i)) cnt++;
	}
	return cnt;
}
bool cmp(obj a,obj b){
	if(a.c==b.c) return a.x>b.x;
	else return a.c>b.c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i].x;
		g[i].c=fun(g[i].x);
	}
	sort(g+1,g+1+n,cmp);
	long long ans=(1ll<<31)-1;
	for(int i=1;i<=m;i++) ans&=g[i].x;
	cout<<ans;
	return 0;
}
