#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,cnt,cnt2;
int a[100005],a2[100005];
char b[100005],b2[100005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n/2;i++){
		cin>>a[i]>>b[i];
		cnt2+=a[i];
	}
	for(int i = 1;i<=(n+1)/2;i++){
		cin>>a2[i]>>b2[i];
		if(b2[i]!=b[n/2-i]){
			cnt+=a2[i];
		}
	}
	cout<<min(cnt,cnt2);
	return 0;
}
