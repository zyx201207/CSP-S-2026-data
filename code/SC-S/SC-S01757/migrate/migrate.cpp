#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt,zls=0,m,ans=0;
int a[500005];
void go(int s,int e,int p){
	if(s==e){
		if(zls==0){
			m=p;
			cnt=1;
			zls=1;
		}else{
			if(p<m){
				m=p;
				cnt=1;
			}else if(p==m){
				cnt++;
			}
		}
		return;
	}
	for(int k=s+1;k<=e;k++){
		if(abs(a[k]-a[s])<=d){
			go(k,e,p+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				cnt=0;
				zls=0;
				go(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}