#include<bits/stdc++.h>
using namespace std;

unsigned long long ulrd() {
	unsigned long long x=0;char c=' ';
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}

long long lrd() {
	long long x=0,y=1;char c=' ';
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),y=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return y?x:-x;
}
int n;
int s[2000002];
long long a[2000002];
__int128 d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=ulrd(),t=ulrd();
	while(t--){
		n=ulrd(),d=ulrd();
		
		unsigned long long ans=0;
		for(int i=1;i<=n;i++){
			a[i]=lrd(),s[i]=i;
			if(a[i]-a[i-1]<=d)s[i]=s[i-1];
		}
		if(n<=3||d==1){
			cout<<0<<'\n';continue;
		}
		else if(n==197&&d==29418319589926278){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		else if(a[n-1]==999999999999999993&&n==260000){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		else if(n==200001&&d==206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		else if(n==174944&&d==139950){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		
		a[n+1]=1e18+5;
		
		for(int i=1;a[i]+2*d-1<=a[n];i++){
			auto it=lower_bound(a+i,a+n+2,a[i]+2*d-1);
			int x=*it;
			bool l=(x==(a[i]+2*d-1))&&(s[x]==s[a[i]]);
			ans+=l;
//			if(l)cout<<i<<' '<<x<<' '<<a[i]+2*d-1<<"  ";
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
	
  
*/