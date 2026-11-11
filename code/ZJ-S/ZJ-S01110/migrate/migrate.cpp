#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,ans,a[1000010];
bool pd(int x,int y){
	long long s=1;
	if(y>x/2) y=x-y;
	for(int i=x,j=y;i>=x-y+1&&j>=1;i--,j--){
		s=s*i/j;
		if(s>2) return 0;
	}
	return s==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				long long s=(a[j]-a[i]-1)/d,x=j-i-1;
				if(pd(x,s)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}