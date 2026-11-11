#include<bits/stdc++.h>
using namespace std;
long long maxn=0,a[100000],m,n;
void ans(long long gs,long long jg,long long cs){
	if(gs==0){maxn=max(maxn,jg);return;}
	if(cs>n)return;
	ans(gs--,jg&=a[cs],cs++);
	ans(gs,jg,cs++);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];	
	for(long long i=1;i<=n;i++)
		ans(m,a[i],i++);
	cout<<maxn;
	return 0;
} 
