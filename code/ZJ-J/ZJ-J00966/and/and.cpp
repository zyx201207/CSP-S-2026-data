#include <bits/stdc++.h>
using namespace std;

int a[200005],b[200005][35];bool f[200005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,maxt=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		int t=a[i];
		b[i][0]=0;
		while(t>1){
			b[i][++b[i][0]]=t%2;
			t/=2;
		}
		b[i][++b[i][0]]=1;
		maxt=max(maxt,b[i][0]);
	}
	for(int j=maxt;j>=1;j--){
		memset(f,false,sizeof(f));
		int COUNT=0;
		for(int i=1;i<=n;i++){
			if(b[i][0]!=-1 && b[i][j]==1){
				COUNT++;
				f[i]=true;
			}
		}if(COUNT>=m){
			for(int i=1;i<=n;i++){
				if(f[i]==false){
					b[i][0]=-1;
				}
			}
			ans+=pow(2,j-1);
		}
	}cout<<ans;
	return 0;
}
