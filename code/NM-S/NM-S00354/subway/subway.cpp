#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005][500005];
int d[500005][500005];
int e[500005][2];
int s[500005][500005];
int x[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c,n,m,d,q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>c[i][1]>>d[i][1];
		for(int j=2;j<b[i];j++){
			cin>>c[i][j]>>d[i][j];
			s[c[i][j-1]][c[i][j]]=1;
			s[c[i][j]][c[i][j-1]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>e[i][1]>>e[i][2];
	}
	for(int i=1;i<=q;i++){
		if(s[e[i][1]][e[i][2]]==1){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=b[i];j++){
					if((c[i][j]==e[i][1]&&c[i][j+1]==e[i][2])||c[i][j+1]==e[i][1]&&c[i][j]==e[i][2]){
						x[i]=a[e[i][1]]+a[e[i][2]]+d[i][j]+d[i][j+1];
						cout<<x[i];
					}
				}
			}
		}else{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
