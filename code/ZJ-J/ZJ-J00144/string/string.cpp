#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,l,r,s;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			s+=(b[l]!=b[r])*a[l];
			l++,r--;
		}
		else if(a[l]<a[r]){
			s+=(b[l]!=b[r])*a[l];
			a[r]-=a[l++];
		}
		else{
			s+=(b[l]!=b[r])*a[r];
			a[l]-=a[r--];
		}
	}
	cout<<s;
	return 0;
}
