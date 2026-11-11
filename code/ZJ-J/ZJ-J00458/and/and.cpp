#include<bits/stdc++.h>
#define f(x,bt) ((x)>>(bt)&1)
using namespace std;
unsigned a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	unsigned n,m,now,ans=0;
	cin>>n>>m;
	for(unsigned i=0;i<n;++i){
		cin>>a[i];
	}
	for(char bit=sizeof a[0]*8-1;bit>=0;--bit){
		now=0;
		for(unsigned i=0;i<n;++i){
			now+=f(a[i],bit);
		}
		if(now>=m){
			for(unsigned i=0;i<n;++i){
				if(!f(a[i],bit))a[i]=0;
			}
			ans|=1<<bit;
		}
	}
	cout<<ans;
}