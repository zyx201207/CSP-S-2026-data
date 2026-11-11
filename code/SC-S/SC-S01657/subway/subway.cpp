#include<bits/stdc++.h>
using namespace std;
int n;
int sum=0;
bool flag=0;
int x[500010],y[500010],o[100010],a[501][500010],t[501];
int tong[500001][490];//tong[i][j]表示第i号地铁站可以连通的第j个路线 

int bl(long long lx,int zt,int sj){
	long long ll,ii;
	for(int i=1;i<=500;i++){
		if(tong[lx][i]==y[i]){
			return o[lx]+o[y[i]];
			break;
		}
	}
	int mi=1000000;
	for(int i=1;i<=500;i++){
		if(tong[lx][i]==y[i]){
			int asd=bl(lx,i,sj);
			if(asd<mi){
				mi=asd;
			}
			for(int j=1;j<=n;j++){
				if(tong[zt][i]!=lx){
					bl(tong[zt][i],zt,sj);
					ll=tong[zt][i];
					ii=zt;
				}
			}
		}
	}
	int ss=sj+o[lx]+mi;
	return bl(ll,ii,ss);
	
}
int main()
{
	int c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>o[i];//从每个地铁站的地铁口走到站厅需要的时间
	for(int i=1;i<=n;i++){
		int asd=0;
		int x;//a[i][j]表示第i条线路经过的第j个地铁站
		cin>>x;
		for(int j=1;j<=2*x;j++){
			cin>>a[i][j]>>t[i];
			tong[a[i][j]][asd]=j;asd++;
		}
	}//t[i]表示从该地铁站的站厅走到第i条线路的站台需要的时间
	
	for(int i=1;i<=q;i++){//分别表示第r个出行计划的起点和终点所在的地铁站编号
		flag=0;
		cin>>x[i]>>y[i];//x起点，y终点 
		
	}
	
	for(int i=1;i<=q;i++){
		for(int j=1;j<=500;j++){
			if(tong[x[j]][j]==y[j]){
				cout<<o[x[j]]+o[y[j]]<<endl;
				flag=1;
				break;
			}
		}
	
	if(flag==0){
			long long asdfg=tong[x[i]][1];
			cout<<bl(asdfg,x[i],0)<<endl;
		}
	}

	return 0;
}
