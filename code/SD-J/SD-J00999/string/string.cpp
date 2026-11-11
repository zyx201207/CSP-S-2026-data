#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],ans,sum;
char s[200010],k[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		b[n-i+1]=a[i];
		k[n-i+1]=s[i];
		sum+=a[i];
	}
	long long cnta=0,cntb=0,idxa=1,idxb=1,lasta=0,lastb=0;
	while(cnta!=sum||cntb!=sum){
		if(cnta<cntb){
			lasta=cnta;
			cnta+=a[idxa];
			idxa++;
		}else if(cnta>cntb){
			lastb=cntb;
			cntb+=b[idxb];
			idxb++;
		}else{
			lasta=cnta;
			lastb=cntb;
			cnta+=a[idxa];
			cntb+=b[idxb];
			idxa++;
			idxb++;
		}
		char x=s[idxa-1],y=k[idxb-1];
		if(x!=y){
			ans+=min(cnta,cntb)-max(lasta,lastb);
		}
	}
	cout<<ans/2;
	return 0;
}
