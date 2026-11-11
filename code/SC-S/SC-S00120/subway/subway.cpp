#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[125255],k[505],a[505][5005],t[505][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int l,r;
	while(q){
		q--;
		int h=0;
		cin>>l>>r;
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==l&&f1){
					h=h+t[i][j];
					f1=false;
				}
				if(a[i][j]==r&&f2){
					h=h+t[i][j];
					f2=false;
				}
			}
		}
		h=h+w[l]+w[r];
		cout<<h<<endl;
	}
	return 0;
}