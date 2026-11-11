#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int N=5e5+5;
int n,d,l[N],f=0,ans=0,a[N];
void dfs(int x,int e,int k){
	if(x==e){
		a[++f]=k;
		return ;
	}
	for(int i=x+1;i<=e;i++){
		if(abs(l[x]-l[i])<=d){
			dfs(i,e,k+1);
		}else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>l[i];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					f=0;
					dfs(i,j,0);
					sort(a+1,a+f+1);
					if(a[1]==a[2]&&a[2]!=a[3]&&f>=2)ans++;
				}
		cout<<ans<<endl;
	}
	return 0;
}

