#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=0,r=n-1,ans=0;
	while(l<r){
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		if(c[l]!=c[r]){
			ans++;
		}
		a[l]--;
		a[r]--;
	}
	cout<<ans;
}
