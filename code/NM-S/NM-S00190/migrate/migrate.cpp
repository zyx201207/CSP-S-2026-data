#include<bits/stdc++.h>
using namespace std;
int c,t,n,N,d;
long long a[2000006],b[2000006],e[2000006];
void bfs(int ks){
	if(e[ks]!=0){
		return;
	}
	e[ks]=1;
	for(int i=ks+1;i<=n;i++){
		if(abs(a[i]-a[ks])<=d){
			b[i]++;
			bfs(i);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		bfs(1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]==2){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			b[i]=0;
			e[i]=0;
		}
		cout <<ans-1<<endl;
	}
	return 0;
} 
