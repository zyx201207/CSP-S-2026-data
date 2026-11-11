#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],n,d,c,t,s;
void so(int x,int y){
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				so(i,j);
			}
		}
	}
	
	return 0;
}
