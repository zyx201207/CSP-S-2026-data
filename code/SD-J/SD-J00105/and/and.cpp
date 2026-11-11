//operater
//priority
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int n,z[N],vis[N],ans,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>z[i];
	for(int id=29;id>=0;id--){
		int sum=0;
		for(int i=1;i<=n;i++)if(z[i]%(1<<(id+1))>=(1<<id)&&!vis[i])sum++;
		if(sum>=m){
			ans+=(1<<id);
			for(int i=1;i<=n;i++)if(z[i]%(1<<(id+1))<(1<<id))vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
} 
