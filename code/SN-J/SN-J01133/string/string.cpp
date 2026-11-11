#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long l=1;
	long long r=n;
	long long ans=0;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>=a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>=a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
