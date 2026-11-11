#include <bits/stdc++.h>
using namespace std;
struct strNode{
	long long a;
	char c;
};
long long change(const vector<strNode> &s);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	scanf("%lld",&n);
	vector<strNode> s(n);
	for(int i=0;i<n;i++)
		scanf("%lld%s",&s[i].a,&s[i].c);
		
	cout<<change(s)<<endl;
	
	return 0;
}
long long change(const vector<strNode> &s){
	long long ans=0;
	long long l=0,nl,r=s.size()-1,nr;
	nl=s[l].a;
	nr=s[r].a;
	
	while(l<=r){
		long long res=0;
		res+=min(nl,nr);
		if(s[l].c!=s[r].c)
			ans+=res;
		if(nl>=nr){
			nl-=nr;
			nr=s[--r].a;
		}else{
			nr-=nl;
			nl=s[++l].a;
		}
	}
	
	return ans;
}

