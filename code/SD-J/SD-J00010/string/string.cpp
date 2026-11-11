#include<bits/stdc++.h>
using namespace std;
long long n,s,l,ans;
char m,a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	for(int i=1;i<=n;i++){
		cin>>s;
		cin>>m;
		for(int j=1;j<=s;j++){
			a[l]=m;
			l++;
		}
	}
	long long r=1;
	long long p=l;
	while(r<p){
		if(a[r]!=a[p]){
			ans++;
		}
		r++;
		p--;
	}
	cout<<ans;
}
