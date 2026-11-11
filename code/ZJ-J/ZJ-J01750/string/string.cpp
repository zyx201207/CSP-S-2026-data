#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[200005];
char b[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l=1,r=n;
	while(1){
		if(l!=r){
			if(a[l]>a[r]){
				ans+=(b[l]!=b[r])*a[r];
				a[l]-=a[r],r--;
			}
			else{
				ans+=(b[l]!=b[r])*a[l];
				a[r]-=a[l],l++;
			}
		}
		else break;
		
	}
	cout<<ans;
	return  0;
}

/*
2
2 a
3 a
*/
