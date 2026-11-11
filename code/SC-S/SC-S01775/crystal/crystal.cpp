#include<bits\stdc++.h>
using namespace std;
unsigned int n,maxn=1;
unsigned long long m;
long long a[500005];
void dfs(unsigned int l,unsigned int r,unsigned long long cnt){
	if(n-l<maxn) return;
	maxn=max(r-l+1,maxn);
	if(r==n-1) return;
	long long cn=cnt-(a[r+1]-a[r])*(r-l+1);
	unsigned int ll=l;
	while(cn<0){
		cn+=(a[r+1]-a[ll]);
		ll++;
	}
	dfs(ll,r+1,cn);
	return;
}
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.ans","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n; i++){
    	cin>>a[i];
    }
    sort(a,a+n);
    dfs(0,0,m);
    cout<<maxn<<"\n";
    return 0;
}