#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sufa[200005];
char c[200005],sufc[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sufa[n-i+1]=a[i];
		cin>>c[i];
		sufc[n-i+1]=c[i];
	}
	long long ans=0,l=1,r=1;
	while(l<=n&&r<=n){
		if(a[l]>=sufa[r]){
			a[l]-=sufa[r];
			if(c[l]!=sufc[r])   ans+=sufa[r];
			r++;
		}
		if(a[l]<=sufa[r]){
			sufa[r]-=a[l];
			if(c[l]!=sufc[r])   ans+=a[l];
			l++;
		}
	}
	cout<<ans/2;
}