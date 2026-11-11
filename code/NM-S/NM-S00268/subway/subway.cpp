#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
long long w[130000];
long long k;
long long a[550],t[550],floyd[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(floyd,0x3f,sizeof(floyd));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int asd=1;asd<j;asd++){
			floyd[a[j]][a[asd]]=floyd[a[asd]][a[j]]=t[j]+t[asd];
		}
	}

	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)floyd[i][j]=0;
				else for(int k=1;k<=m;k++){
					floyd[i][j]=floyd[j][i]=min(floyd[i][k]+floyd[k][j],floyd[i][j]);
				}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<floyd[x][y]+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
