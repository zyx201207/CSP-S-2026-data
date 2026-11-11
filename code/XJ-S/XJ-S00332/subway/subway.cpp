#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=2e4+10;
vector<int>w;
struct at{
	int a;
	int t; 
}arr[510][N];
long long sum[510];
long long sumtime=0;
int zhan[510];
int main(){//dp?
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		zhan[i]=k;
		for(int j=1;j<=k;j++){
			cin>>arr[i][j].a>>arr[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		sumtime=0;
		if(x==y){
			cout<<0;
			continue;
		}
		sumtime+=w[x-1];
		sumtime+=w[y-1];
		sum[1]=arr[1][1].t;
		for(int j=1;j<=n;j++){
			int k=zhan[i];
			for(int z=2;z<=k;z++){
				int dian=arr[j][z].a,dian1=arr[j][z-1].a;
				sum[dian]=sum[dian1]+arr[j][dian].t;
			}
		}
		sumtime+=sum[y];
		cout<<sumtime<<endl;
	}
	return 0;
}
/*分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
每个出行计划的总步行时间为进出站和换乘的步行时间之和*/
