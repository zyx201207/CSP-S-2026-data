#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		int x=min(a[l],a[r]);
		if(s[l]!=s[r]){
			ans+=x;
			a[l]-=x,a[r]-=x;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
		else{
			a[l]-=x,a[r]-=x;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
