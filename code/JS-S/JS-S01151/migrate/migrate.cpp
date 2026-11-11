#include <bits/stdc++.h>
using namespace std;
int n,d,c,t,ans=0,a[2000006];
int rd(){
	int k=0;
	int f=1;
	char c;
	c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-')    f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar_unlocked();
	}
	return k*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++)
			        if((a[i]-a[j])%d!=0&&(a[i]-a[j])/d>0){
					    ans+=(a[i]-a[j]+d-1)/d;
				    }
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
