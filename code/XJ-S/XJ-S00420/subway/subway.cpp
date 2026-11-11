#include<bits/stdc++.h>
using namespace std;
int s[100005],a[1005][1005],t[1005][1005],x[5][100005],y[5][100005],maxx[100005],k[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int l=1;
		cin>>x[l][i]>>y[l][i];
		l++;
	}
	for(int z=1;z<=q;z++){
		int l=1;
		int bj=0;
		for(int i=1;i<=n;i++){
			maxx[i]=0; 
		}
		cnt=s[x[l][z]]+s[y[l][z]];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				maxx[a[i][j]]=max(maxx[a[i][j]],t[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(t[i][j]==maxx[a[i][j]]&&a[i][j]>=x[l][z]&&a[i][j]<=y[l][z]){
					cnt+=maxx[a[i][j]];
					x[l][z]=a[i][j];
					if(x[l][z]==y[l][z]){
						cout<<cnt<<"\n";
						bj=1; 
					} 
				}else{
					cnt+=t[i][j];
					break;
				}
			}
		}
		if(bj!=1){
			cout<<cnt<<"\n";
		}
		l++;
	}
	return 0;
} 
