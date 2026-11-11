#include<bits/stdc++.h>
using namespace std;
int c,t,n,a[2000010],f[20][20],ans[20][20],answer;
long long d;
/*
c:测试点编号(0~25)
t:数据数量(2~1e5) 
n:岛屿数量(1~2e6,∑n<=2e6)
d:单次的最长距离 
*/
void dfs(int c,int frst,int lst,int now){
	/*debug
	cout<<c<<' '<<frst<<' '<<lst<<':'<<now<<'\n';
//	*/
	if(f[frst][lst]==now)
		ans[frst][lst]++;
	else if(f[frst][lst]>now){
		f[frst][lst]=now;
		ans[frst][lst]=1;
	}
	for(int i=c+1;i<=n;i++){
		if(a[i]-a[c]>d)
			break;
		dfs(i,(frst==0 ? c:frst),i,now+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t; 
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c<=2){
			//8`(2/25)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					f[i][j]=INT_MAX;
					ans[i][j]=0;
				}
			dfs(1,0,0,0);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(ans[i][j]==2)
						answer++;
			cout<<answer<<'\n';
		}
		else if(c==11||c==12){
			//8`(2/25)
			if(d>=a[2]-a[1])
				cout<<n-3<<'\n';
			else
				cout<<0<<'\n';
		}
	}
	return 0;
}
/*[(^v^)]*/
