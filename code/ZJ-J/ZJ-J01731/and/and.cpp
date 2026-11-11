#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=2e5;
const int INF=1073741824;
int n,m;
int a[N];
map<int,int> vis;
int f(int x){
	int mmm=INF;
	for(int i=1;i<=30;i++){
		mmm/=2;
		if(x>=mmm){
			return 30-i;
		}
	}
}
int ff(int x,int y){
	int sum=0;
	map<int,int>bb;
	int mmm=INF;
	for(int i=1;i<=30;i++){
		mmm/=2;
		if(x>=mmm){
			x-=mmm;
			bb[mmm]++;
		}
		if(y>=mmm){
			y-=mmm;
			bb[mmm]++;
		}
		if(bb[mmm]=2)sum++;
	}
	if(sum>0){
		vis[x]++;
		vis[y]++;
		return 1;
	}else return 0;
}
bool cmp(int x,int y){
	if(ff(x,y)){
		return f(x)>f(y);
	}else return vis[x]>=vis[y];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
