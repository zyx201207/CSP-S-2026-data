#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],k=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i]; 
	}
	long long l=1,r=1;
	while(l<=n && r<n){
		long long o=b[r]-b[l-1];
		if(o+m>=a[r+1]*(r-l+1)){
			k=max(k,r-l+2);
			r++;
		}else{
			l++;
		}
	}
	cout<<k;
}
