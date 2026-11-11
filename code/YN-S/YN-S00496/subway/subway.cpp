#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[505][50005],l[505][50005],b[50005],f[50005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int c,d;
			cin>>c>>d;
			a[i][c]=d;
		}
	}
	for(int w=1;w<=q;w++){
		int x,y;
		cin>>x>>y;int q=1;
		f[0]=x;
		while(q>0){
			long long xx=f[0];f[0]=0;
			swap(f[0],f[q-1]);
			q--;
			for(int i=1;i<=n;i++){
				if(a[i][xx]>0){
					for(int j=1;j<=m;j++){
						if(a[i][j]>0&&j!=xx){
							f[q++]=j;
							if(l[i][j]==0)
								l[i][j]=(a[i][j]+a[i][xx]+l[i][xx]);
							else
								l[i][j]=min(a[i][j]+a[i][xx]+l[i][xx],l[i][j]);
						}
					}
				}
			}
			sort(f,f+q);
		}
		long long ans=1e12;
		for(int i=1;i<=n;i++){
			if(l[i][y]>0)ans=min(ans,l[i][y]);
		}
		cout<<b[x]+b[y]<<endl;
	}
	return 0;
}
