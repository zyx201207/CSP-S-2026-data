#include<bits/stdc++.h>
#define ll long long
#define N 200100

using namespace std;

struct node{ll x;char c;}p[N];
ll n,a,l,r,ans,numl,numr;char chr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		{cin>>a>>chr;p[i]={a,chr};}
	l=1,r=n,numl=p[l].x,numr=p[r].x;
	while(l<r){
		if(numl>numr){
			if(p[l].c!=p[r].c)ans+=numr;
			numl=numl-numr,numr=p[--r].x;
		}else if(numr>numl){
			if(p[l].c!=p[r].c)ans+=numl;
			numr=numr-numl,numl=p[++l].x;
		}else{
			if(p[l].c!=p[r].c)ans+=numl;
			numl=p[++l].x,numr=p[--r].x;		
		}
	}
	cout<<ans<<"\n";
	return 0;
}
