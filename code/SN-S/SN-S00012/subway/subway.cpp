#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[50005]={0},a[1000100]={0},x[1000100]={0},y[1000100]={0},b[1000100]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[j+u]>>b[j+u];
		}
		u+=2*k;
	}
	int num=0;
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		num+=w[x[i]];
		for(int j=1;j<=y[i];j++){
			if(b[j]==b[j+u]){
				num+=a[b[j]];
			}
		}
		num+=w[y[i]];
		cout<<num<<endl;
	}
	
	return 0;
}

