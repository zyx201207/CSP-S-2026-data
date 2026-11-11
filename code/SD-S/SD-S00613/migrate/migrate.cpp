#include<bits/stdc++.h>
#define int long long
const int N=1e5+7;
using namespace std;
inline int fr(){
	int k=1,s=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ll,pp; ll=fr(); pp=fr();
	while(pp--){
		int n,d; n=fr(); d=fr();
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2){
			cout<<0<<'\n'; continue;
		}
		if(a[n]<d*2 && a[n]>d){
			cout<<1<<'\n'; continue;
		}
		else{
			cout<<0<<'\n'; continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

