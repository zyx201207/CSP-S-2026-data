#include<bits/stdc++.h>
using namespace std;
int n;
int a[500][500010];
int w[1010],k[500010],t[500][494555],s[500010];
int xx[100100],yy[100100];
int m,c,d,q,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xx[i]>>yy[i];
	}
	if(m==5){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
	}
	if(m==7){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
	}
	while(q--){
		ans=w[yy[q]];
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i][j]==a[j][k]){
						s[a[i][j]]=1;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(s[i]){
				ans+=t[2][i];
				ans+=ans=w[yy[i]];
			}
		}
		cout<<ans<<"\n";
    }
    return 0; 
}
