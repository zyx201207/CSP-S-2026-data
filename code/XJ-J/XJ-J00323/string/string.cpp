#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N=2e5+5;
int a[N],n,ans;
string s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				r--,l++;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else{
				ans+=a[l];
				r--,l++;
			}
		}
		//cout<<l<<' '<<r<<'\n';
	}cout<<ans;
	return 0;
}
//aaaabbba
//3 4 a 3 b 1 a
