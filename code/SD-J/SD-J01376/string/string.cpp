#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std; 
int n,ans;
int a[400009];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n;
	s=".";
	for(int i=1;i<=n;i++){
		string c;
		cin>>a[i]>>c;
		s+=c;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				r--;
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
return 0;
}
