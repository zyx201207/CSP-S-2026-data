#include<bits/stdc++.h>
using namespace std;
int ting[500005],xian[505];
int zhan[505][505],tai[505][505];
int qi[100005],zhong[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ting[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>xian[i];
		for(int j=1;j<=xian[i];j++){
			cin>>zhan[xian[i]][j]>>tai[xian[i]][j];
		}
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		bool flag=0;
		cin>>qi[i]>>zhong[i];
		sum+=ting[qi[i]];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=xian[i];k++){
				if(zhan[k][i]==qi[i]){
					sum+=tai[k][i];
				}
				if(zhan[k][i]==zhong[i]){
					flag=1;
					continue;
				}
			}
			if(flag==1){
				continue;
			}
		}
		sum+=ting[zhong[i]];
		cout<<sum<<"\n";
	}
	return 0;
}

