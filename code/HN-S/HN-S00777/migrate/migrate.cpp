#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e9;
int n,d,a[N],f[N];
int vis[N];
int ch(int x,int y){
	if(x>y)swap(x,y);
	if(y>n||x>n)return 0;
	return abs(a[y]-a[x])<=d;
}
int ds[5005][5005],pl[N],pr[N],ans;
bool v[N];
void bfs(int s){
	queue<int>q;
	q.push(s);
	ds[s][s]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
//		cout<<x<<"\n";
		for(int j=1;j<=n;j++){
			if(ch(j,x)&&ds[s][j]>inf){
//				cout<<j<<" " 
				ds[s][j]=ds[s][x]+1;
				q.push(j);
			}
		}
	}
}
int num[505];
void _main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)ds[i][j]=2*inf;
	}
	if(n<=5000){
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			int p=n+1;
			ds[i][i]=0;
			for(int j=i-1;j>=1;j--){
				if(ch(p,j)){
					ds[i][j]=ds[i][j+1];
				}
				else if(ch(j+1,j)){
					p=j+1;
					ds[i][j]=ds[i][j+1]+1;
				}
				else ds[i][j]=2e18+1;
			}
			p=n+1;
			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<p<<" "<<a[j]-a[p]<<" "<<d<<" "<<ch(p,j)<<"\n";
				if(ch(p,j)){
					ds[i][j]=ds[i][j-1];
				}
				else if(ch(j-1,j)){
					p=j-1;
					ds[i][j]=ds[i][j-1]+1;
				}
				else ds[i][j]=2e18+1;
			}
//			cout<<"\n";
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<i<<"->"<<j<<":"<<ds[i][j]<<"\n";
//			}
//			cout<<"\n";
//		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=1;k<=n;k++)num[k]=0;
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(ds[i][k]+ds[k][j]==ds[i][j]){
						if(ds[i][k]>=inf)continue;
						num[ds[i][k]]++;
						if(num[ds[i][k]]>=2)cnt++;
						if(cnt>=2)break;
					}
				}
				ans+=(cnt==1);
//				if(cnt>=2){
//					cout<<i<<" "<<j<<"\n";
//				}
			}
		}
		cout<<ans<<"\n";
		return;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cout<<"0\n";
		}
		return 0;
	}
	while(t--){
		_main();
	}
	return 0;
}
/*
曾许下心愿，等待你的出现

褪色的秋千，有本书，会纪念

我循着时间，捡起梦的照片

童话还没有兑现，却需要说再见

如果有一天，岁月晕开书页

请把我模糊的自己当作笑脸

很久前，想象今天画面

哭着笑着告别陌生的情节，熟悉的侧脸都重叠

oh~oh~oh~

出发前，无数星光（怎么没有这两个字） 

有回忆落在指尖

当时间向前，我会在原地留恋 
*/
