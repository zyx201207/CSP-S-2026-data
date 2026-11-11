#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=3e3+5;
int a[N],l[M],ans[M];
bool ex[N][N],q[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!l[a[i]]){
			l[a[i]]=i;
		}for(int j=1;j<=i;j++){
			ex[i][j]=1;
		}
	}for(int i=1;i<=n;i++){
		if(l[a[i]]>=i){
			continue;
		}int nl=l[a[i]];
		for(int j=i-1;j>=nl;j--){
			for(int k=1;k<=nl;k++){
				if(ex[nl][k]){
					ex[j][k]=0;
				}
			}
		}l[a[i]]=i;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(ex[i][j]){
				ans[a[i]]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}cout<<'\n';
	return 0;
}
