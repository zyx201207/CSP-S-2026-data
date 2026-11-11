#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N=2000005;

struct ss{
	int m;
	char c;
}s[N];

ll n,ans,l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		int m;
		char c;
		cin>>m>>c;
		if(i>1&&c==s[i-1].c) s[i-1].m+=m;
		else s[i].c=c,s[i].m=m;
	}
	l=1;r=n;
//	cout<<l<<" "<<r<<" "<<ans<<endl;
	while(l<r){
		if(s[l].m>=s[r].m){
			if(s[l].c!=s[r].c) ans+=s[r].m;
			s[l].m-=s[r].m;s[r].m=0;
			--r;
		}else if(s[l].m<s[r].m){
			if(s[l].c!=s[r].c) ans+=s[l].m;
			s[r].m-=s[l].m;s[l].m=0;
			++l; 
		}
//		cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	
	cout<<ans;
	
	return 0;
}
