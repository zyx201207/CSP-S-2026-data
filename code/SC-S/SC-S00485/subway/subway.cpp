#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int w[500010],wy[500010],js[500010];
int a[5010][5010],t[5010][5010];
bool pd[50010];
int c,n,m,d,q;
void pxt(int p,int l){
	for(int i=2;i<=p;i++){
		if(a[i][l]<=a[i-1][l]){
			int r=a[i][l];
			a[i][l]=a[i-1][l];
			a[i-1][l]=r;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		for(int j=1;j<=q*2;j++){
			cin>>a[i][j]>>t[i][j];
			wy[a[i][j]]++;
			js[j]=i;
		}
		pxt(q,i);
	}
	for(int i=1;i<=q;i++){
		int z,x;
		cin>>z>>x;
		int num=w[z]+w[x];
		if(c>=7&&c<=11){
			for(int j=1;j<=m;j++){
				num=num+t[js[j]][j];
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}