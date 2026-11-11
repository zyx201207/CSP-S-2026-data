#include<bits/stdc++.h>
using namespace std;
long long n,d,t,c,a[1000005],ans;
bool f(int x,int y){
	int g=0;
	for(int i=x+1;i<=y-1;i++){
		if(a[i]-a[x]<=d&&a[y]-a[i]<=d)
		g++;
		if(g>=3)
		break;
	}
	if(g==2)
	return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=3;a[i+j]-a[i]<2*d;j++)
			if(a[i+j]-a[i]<2*d&&a[i+j]-a[i]>d&&f(i,i+j))
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
