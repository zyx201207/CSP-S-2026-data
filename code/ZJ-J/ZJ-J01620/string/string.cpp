#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long s,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	if(s%2==1){
		s--;
	}
	s/=2;
	long long pa=a[1];
	char pc=c[1];
	int ppa=1,ppc=1;
	for(int i=2;i<=n;i++){
		if(pa!=a[i]){
			ppa=0;
		}
		if(pc!=c[i]){
			ppc=0;
		}
	}
	if(ppc==1){
		cout<<0;
		return 0;
	}
	else if(ppa==1){
		long long ans=0,ttt=pa;
		string str;
		for(int i=1;i<=n;i++){
			str=str+c[i];
		}
		for(int i=0;i<str.size()/2-1;i++){
			if(str[i]!=str[str.size()-i]){
				ans++;
			}
		}
		cout<<ans*ttt;
	}
	else{
		long long ti1=0,ti2=n,tj1=0,tj2=a[n]+1;
		while(s--){
			tj1++;
			tj2--;
			if(tj1>a[ti1]){
				ti1++;
				tj1=0;
			}
			if(tj2<1){
				ti2--;
				tj2=a[ti2]+1;
			}
			if(c[ti1]!=c[ti2]){
				ans++;	
			}
		}
		cout<<ans;
	}
	return 0;
}
