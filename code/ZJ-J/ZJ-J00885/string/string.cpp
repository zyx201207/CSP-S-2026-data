#include<bits/stdc++.h>
using namespace std;
long long n,x[200010],i,j,m,ans,t,w,mi;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	t=1;
	w=n;
	while(t<w){
		if(c[t]==c[w]){
			mi=1e18;
			mi=min(x[t],x[w]);
			x[t]-=mi;
			x[w]-=mi;
			if(x[t]==0) t++;
			if(x[w]==0) w--;
		}else{
			mi=1e18;
			mi=min(x[t],x[w]);
			ans+=mi;
			x[t]-=mi;
			x[w]-=mi;
			if(x[t]==0) t++;
			if(x[w]==0) w--;
		}
	}
	cout<<ans;
	return 0;
}
