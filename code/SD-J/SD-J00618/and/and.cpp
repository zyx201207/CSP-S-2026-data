#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
	long long a,b;
}s[200005];
bool cmp(node sa,node sb){
	if(sa.b==sb.b)return sa.a>sb.a;
	return sa.b>sb.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
	}
	for(int i=1;i<=n;i++){
		long long c=0,t=s[i].a;
		while(t){
			t&=t-1;
			c++;
		}
		s[i].b=c;
	}
	sort(s+1,s+1+n,cmp);
	long long ans=0x7fffffff;
	for(int i=1;i<=m;i++){
		ans&=s[i].a;
	}
	cout<<ans;
	return 0;
}
//expected 100pts      5/5
