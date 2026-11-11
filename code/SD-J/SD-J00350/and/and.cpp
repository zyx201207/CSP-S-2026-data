#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//2147483647
int xxxx=-1;
int n,m,a[200003],f[200003]={xxxx},ans,vis[200003],maxx;
void dfs(int jin,int jin2,int zhi){
	if(jin>n||jin2==m){
		ans=max(ans,zhi);return;
	}for(int i=jin+1;i<=n;i++){
		dfs(i,jin2+1,zhi&a[i]);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=xxxx;
	}for(int i=1;i<=n;i++){
		cin>>a[i];f[i]=f[i-1]&a[i];maxx=max(a[i],maxx);
	}//memset(f,-1,sizeof(f));
	if(n<=20){
		dfs(0,0,-1);
		cout<<ans;
	}if(20<n&&n<=2000){
		if(m==1){
			cout<<maxx;
		}if(m==n){
			cout<<f[n];
		}
	}
	return 0;
}//wupin n
//tiji m
//pertiji 1
//jiazhi ans
/*01bag
//55pts
e1 1-5
e2 13
E3 6
E4 7
E5 8-10
E6 11-12
E7 20
E8 14-15
E9 16-17
E10 18-19
for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){
			f[j]=max(f[j],(f[j-v[i]]+w[i]));
		}
	}
*/
