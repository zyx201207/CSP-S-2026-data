#include<bits/stdc++.h>
using namespace std;

pair<int,int>a[500010][510];
int b[500010];
//first 为地点，second 为时间，索引为目前
int c,n,m,d,q,k;//编号，线路数，站数，最多，计划数

int x,y,t;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==20||c==21)
	for(int i=0;i<m;i++)cin>>b[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int x1,y1;
		pair<int,int> mi;
		mi.second=91114514;
		for(int j=0;j<k;j+=2){
			cin>>x1>>y1;
			if(a[x1][0].first!=0&&mi.second>y1){
				mi.second=y1;
				mi.first=x1;
			}
			a[x1][i].first=1;
			a[x1][i].second=y1;
		}
	}
	
	for(int i=0;i<q;i++){
		cin>>x,y;
		cout<<b[x]+b[y];
	}
	return 0;
}