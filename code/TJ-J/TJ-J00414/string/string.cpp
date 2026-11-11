#include<bits/stdc++.h>
using namespace std;
char a[10000005];
int n,p;
int maxn;
char q;
int l,r;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	l=1;
	for(int i=1;i<=n;i++){
		cin>>p>>q;
		maxn+=p;
		r=maxn;
		for(int j=l;j<=r;j++){
			a[j]=q;
		}
		l=r;
	}
	l=0;
	r=maxn+1;
	for(int i=1;i<=maxn;i++){
		l++;
		r--;
		if(l==r||l>r){
			cout<<ans;
			return 0;
		}
		if(a[l]!=a[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
