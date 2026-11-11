#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1000001;
int c,n,m,d,q;
//c:测试点编号  n:地铁线路数  m:地铁站数  d:每个地铁站最多被几条线路经过  q:出行计划数
int x,y;
long long w[MAXN];//每个地铁站的地铁口走到站厅需要的时间
long long a[MAXN],t[MAXN],k;//a[]:表示第 i 条线路经过的第 j 个地铁站  t[]:从该地铁站的站厅走到第 i 条线路的站台需要的时间
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<long long>arr(n);
	vector<long long>time(m);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int d=1;d<=k;d++){
			cin>>a[d]>>t[d];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	for(int j=1;j<=n;j+=2){
		arr[j]=arr[j]+time[j];
		for(int d=2;d<=n;d+=2){
			arr[j]+=arr[d];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
} 
