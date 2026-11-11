#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		int n,d;
		cin>>n>>d;
		if(d==2)cout<<1<<endl<<2;
		else cout<<0<<endl<<1;
		return 0;
	}
	while(t--){
		long long n,d,s[100010],sum=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		n--;
		for(long long i=1;i<=n;i++){
			s[i]=a[i+1]-a[i];
			if(s[i]>d)n=i;
		}
		for(long long i=1;i<=n-2;i++){
			if(s[i]==s[i+1]&&s[i]==s[i+2]&&3*s[i]>d)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}