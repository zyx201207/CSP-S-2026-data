#include<bits/stdc++.h>
using namespace std;
const int N = 500010,M = 10010;
typedef long long LL;
bool zs = true,yong = true;
int a[N],vis[M],an,ans,x,wyt,maa,mii;
LL n,m;
queue<int> q;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m--;
	cin>>a[0]>>a[1];
	int cha = a[1]-a[0];
	int pian;
	if(a[0] < 0) pian = -a[0];
	else if(a[0] > 0) pian = -a[0];
	else pian = 0;
	vis[0]++;
	vis[a[1]+pian]++;
	for(int i = 2;i < n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=cha) yong = false;
		maa = max(maa,a[i]),mii = min(mii,a[i]);
		if(maa > M||abs(mii) > M){
			int ma = m;
			for(int j = i + 1;j < n;j++) cin>>x;
			int wyt = cha;
			while(ma >= 0&&ma >= wyt){
				if(zs) zs = false,ma-=wyt;
		        else zs = true,ma-=wyt,wyt+=cha;
		        ans++;
			}
			cout<<ans+1;
			return 0;
		}
		vis[a[i]+pian]++;
	}
	if(yong == true){
		int ma = m;
			int wyt = cha;
			while(ma >= 0&&ma >= wyt){
				if(zs) zs = false,ma-=wyt;
		        else zs = true,ma-=wyt,wyt+=cha;
		        ans++;
			}
			cout<<ans+1;
			return 0;
	}
	for(int i = 0;i < m;i++){
		if(vis[i]) ans+=vis[i];
	}
	an = ans;
	int h = 0,t = m-1;
	while(t <= n){
		if(vis[h]) ans-=vis[h];
		h++,t++;
		if(vis[t]) ans+=vis[t];
		an = max(ans,an);
	}
	cout<<an;
}
