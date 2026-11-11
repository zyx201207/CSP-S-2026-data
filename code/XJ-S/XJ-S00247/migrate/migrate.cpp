#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c,t,n,d,x[N],ans;
bool ch(int u,int v,int cnt){
	for(int i=u;i<=v;i++){
		if(abs(x[i]-x[i+2])<=d){
			cnt++;
		}
	}
	if(cnt==2){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])>d&&abs(i-j)>2){
					if(ch(i,j,0)){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
