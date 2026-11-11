#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
const int N=5005;
int a[N];
struct node{
	int x,num;
}p[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			p[i][i].x=0;
			for(int j=i+1;j<=n;j++){
				p[i][j].x=1e18,p[i][j].num=1;
			}
		}for(int i=1;i<=n;i++)cin>>a[i];
		for(int len=1;len<n;len++){
			for(int l=1;l<=n-len;l++){
				int r=l+len;
				if(a[r]-a[l]<=d){
					p[l][r].x=1;p[l][r].num=1;continue;
				}for(int k=l+1;k<r;k++){
					if(p[l][k].x+p[k][r].x<p[l][r].x){
						p[l][r].x=p[l][k].x+p[k][r].x;p[l][r].num=1;
					}else if(p[l][k].x+p[k][r].x==p[l][r].x)p[l][r].num++;
				}
			}
		}int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(p[i][j].num==2){
					sum++;
				}
			}
		}cout<<sum<<endl;
	}
	return 0;
} 