#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t,n,d;
	cin>>c>>t;
	int lry[10010],jkx[10];
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			
			cin>>lry[j];
			if(n>2*d){
				jkx[j]=2;
			}
			else if(n=2*d){
				jkx[j]=1;
			}
			else{
				jkx[j]=0;
			}
		}
		cout<<jkx[i];
	}
	return 0;
}