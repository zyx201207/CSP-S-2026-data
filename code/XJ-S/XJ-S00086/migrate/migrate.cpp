#include<bits/stdc++.h>
using namespace std;
const int N=10e5+10;
long long n,c,t,d,cnt,ans;
int a[N],rode[N];
bool b[N];
void dfs(int x){
	if(x==a[n-1]) ans++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[x]==0){
				b[x]=1;
				x++;
				dfs(a[x]);
				b[x]=0;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dfs(a[i]);
			b[i]=1;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
