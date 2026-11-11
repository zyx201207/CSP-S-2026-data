#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],ans,cnt;
long long dfs(long long x,long long y){
	long long w=0;
	while(x!=y){
		long long t=x+1;
		while(a[t]-a[x]<=d&&t<=y)t++;
		if(t==x+1)break;
		if(t<=y){
			x=t-1;w++;
		}else{
			w++;break;
		}
	}return w;
}
void bb(long long x,long long y,long long w){
	if(x==y){
		if(w==ans)cnt++;
		return;
	}
	long long i=x+1;
	while(a[i]-a[x]<=d&&i<=y){
		bb(i,y,w+1);
		i++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long p=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					ans=dfs(i,j);
					if(ans==0)continue;
					cnt=0;
					bb(i,j,0);
					if(cnt==2){
						p++;
					}
				}
			}
		}
		cout<<p<<"\n";
	}
	return 0;
}
