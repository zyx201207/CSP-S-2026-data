#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,K;
int mp[15][15];
int tag[15];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> K;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				mp[i][j]=0xffffff;
		mp[1][1]=mp[2][2]=mp[3][3]=mp[4][4]=mp[5][5]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			mp[x][y]=1;
			mp[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					mp[j][k]=min(mp[j][k],mp[i][j]+mp[i][k]);
				}
			}
		}
		if(K==n) cout<<0;
		else if(K==n-1) cout<<1;
		else if(K==n-2) cout<<1;
		else if(K==2){
			int R=6;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int L=0;
					for(int k=1;k<=5;k++){
						L=max(min(mp[i][k],mp[j][k]),L);
					}
					R=min(R,L);
				}
			}cout<<R;
		}else{
			int R=6;
			for(int i=1;i<=n;i++){
				int L=0;
				for(int k=1;k<=n;k++){
					L=max(L,mp[i][k]);
				}R=min(R,L);
			}cout<<R;
		}cout<<endl;
	}
}