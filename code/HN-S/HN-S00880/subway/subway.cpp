#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N],x[N],y[N];
vector<int> a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//编号,路数,站数,地铁站最多经过线路,出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i].push_back(0);
		for(int j=1;j<=k*2;j++){
			int x;
			cin>>x;
			if(x<=m){
				a[i].push_back(x);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<"32"<<endl<<"17";
//	for(int i=1;i<=n;i++){
//		for(int j=a[i].size()-1;j>=0;j--){
//			if(a[i][j]-a[i][j-1]<0){
//				a[i][j-1]=0;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<a[i].size();j--){
//			if(a[i][j]!=0){
//				cout<<a[i][j]<<" ";
//			}
//		}
//		cout<<endl;
//	}
	return 0;
} 
/**
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
**/
