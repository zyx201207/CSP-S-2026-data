#include<bits/stdc++.h>
using namespace std;
int cr,t,n,d,a[2000006],ans=0,cnt,j,k,mi;
void solve(int s,int f){
	if(cnt>2) return;
	if(s==j && f<=mi){
		cnt++;
		return;
	}
	for(int i=1;i<=j-s;i++){
		if(a[s+i]-a[s]<=d) solve(s+i,f++);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cr>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		k=1;
		for(int i=1;i<=n;i++){
			for(j=k+2;j<=n;j++){
				mi=(a[j]-a[k])/d;
				cnt=0;
				solve(k,0);
				if(cnt==2) ans++;
			}
			ans--;
			k++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

