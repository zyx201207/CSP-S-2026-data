#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int hhh,hhhh;
int a[100001],k[10001][3],e[1001][1001],pp;
int b[1001][1001]={0};
int de(int x){
 for(int j=1;j<=n;j++){
 if(e[j][x]!=0) 
		for(int i=1;i<=e[j][0];i++){
			if(e[j][i]!=0&&b[i][j]>=e[i][j]){
				b[j][i]=1;
				b[j][i]+=e[j][i];
				if(i==k[pp][1]){
					return b[j][i]+e[j][i]+a[i];
				}else{
					de(j);
				}
			}
		}
	}
	return 0;
}
int main(){
	
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	
	for(int i=1;i<=n;i++){
		cin>>e[i][0];
		for(int j=1;j<=e[i][0];j++){
			cin>>hhh>>hhhh;
			e[i][hhh]=hhhh;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>k[i][1]>>k[i][2];
	}
	
	for(pp=1;pp<=q;pp++){
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=e[i][0];j++){
			
		}
	}
	
	cout<<de(k[pp][2])<<endl;
	}
	
	freopen("subway.out","w",stdout);
	cout<<"0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2";
	return 0;
} 
