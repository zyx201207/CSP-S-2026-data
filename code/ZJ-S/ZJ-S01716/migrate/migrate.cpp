#include <bits/stdc++.h>
using namespace std;
const long long N=1e18;
int c,t;
int n;
long long d;
int a[1000000];
long long b[100][100];
int sum=0;
void dfs(int x,int y,int num){
	b[sum][num]=x;
	if(x==y){
		return ;
	}
	for(int q=x;q<=y;q++){
		if(a[q]-a[x]<=d){
			dfs(q,y,num+1);
		}
	}
	return ;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+0,a+n);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				else{
					dfs(i,j,0);
				}
			}
		}
		t--;
	}
	return 0;
}
