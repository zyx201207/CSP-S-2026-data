#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,s[N],a[N];
long long tot,suf[N];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c;
		a[i]=c-96;
		tot+=s[i];
	}
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+s[i];
	long long s1=0,last=0,ans=0;
	tot=tot/2;
	for(int i=1,j=n;i<=n;i++){
		s1+=s[i];
		if(s1>tot) s1=tot;
		while(suf[j]<=s1){
			if(a[j]!=a[i]) ans+=(suf[j]-last);
			last=suf[j];
			j--;
		}
		if(a[j]!=a[i]) ans+=(s1-last);
		last=s1;
		if(s1==tot) break;
	}
	cout<<ans<<'\n';
	return 0;
}
