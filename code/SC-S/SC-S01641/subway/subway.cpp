#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;

int mp[5001][5001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sebway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a[501][25],t[501][25];
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		int upa;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=0){
				mp[a[i][j]][upa]=1;
				mp[upa][a[i][j]]=1;
			}
			upa=a[i][j];	
		}
	}
	int x[q+1],y[q+1];
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++){
		int ans=w[x[i]-1]+w[y[i]-1];
		int min1=10000086;
		for(int i=0;i<n;i++){
			int sum=t[i][x[i]-1]+t[i][y[i]-1];
			min1=min(sum,min1);
		}
		cout<<min1<<endl;
	}
	return 0;
}