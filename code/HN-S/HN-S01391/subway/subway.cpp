#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p; 
int s[505],k[500005],ii[500005][500005],a[500005][500005],op[100005][2],ans[100005];
int hc(int x,int y){
	bool d=0,e=0;
	bool g=0,h=0;
	int ans2=100000000,ans3=100000000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;i++){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>ii[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>op[i][1>op[i][2]];
	}
	for(int i=1;i<=p;i++){
		ans[i]=s[op[i][1]]+s[op[i][2]];
		
	}
	for(int i=1;i<=p;i++){
		cout<<ans[i];
	}
	return 0;
} 
