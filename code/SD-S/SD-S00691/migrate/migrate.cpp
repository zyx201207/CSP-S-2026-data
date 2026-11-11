#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
ll c,t,n,d,a[N],ans[N][N],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ans[i][i+1]=1;
			for(int j=i+1;j<=n;j++){
				ll minn=0x3f3f3f3f3f3f3f3f,mincnt=0;
				for(int k=i;k<j;k++){
					ll len;
					if(a[j]-a[k]<=d){
						len=ans[i][k]+1;
						if(len<minn){
							minn=len;
							mincnt=1;
						}
						else if(len==minn){
							mincnt++;
						}
					}
				}
				ans[i][j]=minn;
				if(mincnt==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
