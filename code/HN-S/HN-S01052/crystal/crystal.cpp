#include<bits/stdc++.h>
using namespace std;
const int xy=555555;
int n,c=-1e9;
long long k,u[xy],s[xy];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>u[i];
	sort(u+1,u+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+u[n]-u[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,m=0;
		while(l<r){
			m=(l+r)/2;
			long long h=(s[i]-s[m-1]-(i-m+1)*(u[n]-u[i]));
			if(h>k)l=m+1;
			else if(h<k)r=m;
			else{
				c=max(c,i-m+1);
				break;
			}
		}
		if(l==r)c=max(c,i-l+1);
	}
	cout<<c;
	return 0;
}
