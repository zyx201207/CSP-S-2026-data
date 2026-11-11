#include<bits/stdc++.h>
using namespace std;
struct ee{
	long long a;
	char c;
}s[214514];
long long n,a,ans=0,cnt=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		ee ks;
		ks.a=a,ks.c=c;
		s[++cnt]=ks;
	}
	long long i=1,j=cnt;
	while(j>i){
		if(s[i].a==0) i++;
		if(s[j].a==0) j--;
	//	cout<<s[i].a<<' '<<s[i].c<<' '<<s[j].a<<' '<<s[j].c<<'\n';
		char cc=s[i].c,ccc=s[j].c;
		long long jq=min(s[i].a,s[j].a); 
		if(cc==ccc){
			s[i].a-=jq;
			s[j].a-=jq;
		}
		else{
			s[i].a-=jq;
			s[j].a-=jq;
			ans+=jq;
		}
	}
	cout<<ans;
	return 0;
}
