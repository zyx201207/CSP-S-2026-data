#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n,ll=a[1],rl=a[n];
	long long ans=0;
	while(l<r){
		if(ll==rl){
			ans+=ll*(s[l]!=s[r]);			
			l++,r--;
			ll=a[l];
			rl=a[r];
		}
		else if(ll>rl){
			ans+=rl*(s[l]!=s[r]);
			ll-=rl;
			r--;
			rl=a[r];	
		}
		else{
			ans+=ll*(s[l]!=s[r]);	
			rl-=ll;
			l++;
			ll=a[l];
		}
	}
	cout<<ans;
	return 0;
} 
