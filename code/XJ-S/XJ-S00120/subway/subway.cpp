#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int c,n,m,d,q;
int w[N],k[N];
struct node{
	int a,t;
}b[510][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
	}
	for(int z=1;z<=q;z++){
		int r1,r2;
		cin>>r1>>r2;
		int now=1e9+10;
		for(int i=1;i<=n;i++){
			int flag=0,flag2=0;
			for(int j=1;j<=k[i];j++){
				if(b[i][j].a==r1){
					flag=1;
				}
				if(b[i][j].a==r2){
					flag2=1;
				}
			}
			if(flag==1&&flag2==1)now=min(w[r1]+w[r2]+b[i][r1].t+b[i][r2].t,now);
		}
		cout<<now<<endl;
	}
	
	return 0;
} /*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
2 5

*/
