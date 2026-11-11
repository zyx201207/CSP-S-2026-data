//南亭序 西安市第二十五中学 SN-S00364
#include <bits/stdc++.h>
//#define int long long 
using namespace std;
int C,n,m,d,p,w[501005],x[100005],y[100005];
//struct son{
//	int id,dis;
//};
//vector<son> sb[501005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >>C>>n>>m>>d>>p;
	for(int i=1;i<=n;i++){
		cout <<1<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cin >>w[i];
//	}
//	for(int i=1;i<=n;i++){
//		cout <<1;
//		int k;
//		cin >>k;
//		int a[101005]={0},t[101005]={0};
//		for(int j = 1;j<=k;j++){
//			cin >>a[j]>>t[j];
//		}
//		for(int j=i;j<=k;j++){
//			son z={a[j],t[j]},f={i,t[j]};
//			sb[i+m].push_back(z);
//			sb[a[j]].push_back(f);
//		}
//	}
//	for(int i=1;i<=p;i++){
//		cin >>x[i]>>y[i];
//	}
//	for(int o=1;o<=n;o++){
//		int bj[101005]={0},dis[101005];
//		for(int i=0;i<=n;i++) dis[i] = 1e9;
//		dis[x[o]] = 0;
//		for(int i=1;i<=n;i++){
//			int d=1e9,t;
//			for(int j=1;j<=n;j++){
//				if(dis[j]<dis[d]){
//					t=j;
//					d=dis[j];
//				}
//			}
//			for(int j=0;j<sb[t].size();j++){
//				int h=sb[t][j].id;
//				dis[h] = min(dis[h],dis[t]+sb[t][j].dis);
//			}
//		}
//		cout <<dis[y[o]]<<endl;
//	}
	return 0;
}
