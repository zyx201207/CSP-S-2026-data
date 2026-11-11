#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
struct A{
	long long a=0,b=1;
}s[500010];
long long sum[500010],sum1[500010];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	if(m>=1e9){
		cin>>a[1]>>a[2];
		long long c=a[2]-a[1];
		long long qwe=m/c;
		long long o=0;
		for(int i=1;i<=100000;i++){
			if(o+i>qwe){
				cout<<i-1;
				return 0;
			}o+=i;
		}
	}
	cin>>n>>m;
	long long l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	s[1].a=0;
	s[1].b=1;
	for(long long i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			l++;
			s[l].a=a[i]-a[i-1];
		}else{
			s[l].b++;
		}
	}
//	cout<<l;
	for(long long i=1;i<=l;i++){
//		cout<<s[i].a<<" "<<s[i].b<<"\n";
		sum[i]=sum[i-1]+s[i].a;
		sum1[i]=sum1[i-1]+s[i].b;
	}
	for(long long i=l;i>=1;i--){
		long long r=1,q=m,w=s[i].b;
		while(q&&i-r){
			long long c=sum[i]-sum[i-r];
			if(q/c>s[i-r].b){
				w+=s[i-r].b;
				q-=s[i-r].b*c;
				r++;
			}else{
				w+=m/c;
				break;
			}
		}ans=max(ans,w);
	}
	cout<<ans;
	return 0;
}