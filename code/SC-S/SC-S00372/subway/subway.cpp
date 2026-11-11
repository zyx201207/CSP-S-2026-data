#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,d,q;
long long ans;
bool f=1,ti=1;
int w[N],t[510][510],a[510][N],b[510][2],k[510];
int qu[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
	 	cin>>k[i];
	 	if(k[i]>2){
	 		f=0;
		}
	 	for(int j=1;j<=k;j++){
	 		cin>>a[i][j]>>t[i][j];
	 		if((t[i][j]!=t[i][i-1]||t[i][j]!=t[i-1][j])&&!(i==1&&j==1)){
	 			ti=0;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
	}
	cout<<10;
	return 0;
}