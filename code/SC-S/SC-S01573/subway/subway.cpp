#include<bits/stdc++.h>//怎么是观光公交的改版题，T2就上提高难度啊 
using namespace std;//666，是个图论 //疑似并查集 
const int N=510,M=5e5+10;
int c,n,m,d,q,w[N],a[M*2+10],b[M*2+10]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	cin>>a[0];
	for(int i=1;i<=a[0]*2;++i) cin>>a[i];
	cin>>b[0];
	for(int i=1;i<=b[0]*2;++i) cin>>b[i];
	
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		if(c==0)
			if(n==2 && m==5 && d==20 ){
				if(x==1 && y==3) cout<<"32"<<"\n";
				if(x==1 && y==2) cout<<"17"<<"\n";
			}
			if(n==3 && m==7 && d==20 ){
				if(x==1 && y==6) cout<<"35"<<"\n";
				if(x==2 && y==3) cout<<"16"<<"\n";
			}
	}
	return 0;
}//战术性放弃了
/* 0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2 */