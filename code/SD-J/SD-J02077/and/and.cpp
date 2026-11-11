#include<bits/stdc++.h>
using namespace std;
int m,n,res,ans=100000000,e;
int a,c[1073741834];
bool b[1073741834][1073741834],d[1073741834];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a!=0){
			b[c[i-1]][i-1]=a%2;
			c[i-1]++;
			a/=2;
		}
		ans=min(ans,c[i-1]);
	}
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<m-1;j++){
			for(int k=0;k<ans;k++){
				if(b[k][j]==1&&b[k][j+1]==1){
					d[k]=1;
				}else{
					d[k]=0;
				}
			}
		}
		res=0;
		for(int j=0;j<ans;j++){
			res+=d[j]*pow(2,j);
		}
		e=max(e,res);
	}
	cout<<e;
	return 0;
}

