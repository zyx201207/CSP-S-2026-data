#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],c[105],vis[N];
int b[N][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i];
		int x=0;
		while(k){
			b[i][x++]=k%2;
			k/=2;
		}
	}
	long long ma=-1,loc=0;
	memset(c,1,sizeof(c));
	for(int k=1;k<=m;k++){
		ma=-1,loc=0;
		for(int i=1;i<=n;i++){
			for(int j=31;j>=0;j--){
				if(b[i][j]==1&&!vis[i]){
					if(j>ma){
						ma=j;
						loc=i;
					}
					
				}
			}
		}
		vis[loc]=1;
		for(int i=0;i<=ma;i++){
			c[i]&=b[loc][i];
		}
	}
	long long sum=0,op=1;
	for(int i=ma;i>=0;i--){
		sum+=c[ma-i]*op;
		op*=2;
	} 
	cout<<sum;
	return 0;
} 
