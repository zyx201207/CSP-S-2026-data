#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
long long cnt;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]) cnt+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r--];
		}
		else if(a[l]<a[r]){
			a[r]-=a[l++];
		} 
		else l++,r--;
	}
	cout<<cnt;
	return 0;	
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
