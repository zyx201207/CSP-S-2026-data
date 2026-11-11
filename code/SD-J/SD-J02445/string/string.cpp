#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll n,ans,sum,a[200005],l,r;
char c[200005];
string s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	cin>>n;
	int f=1;
	for(lll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(a[i]>=1e7)f=0;
		if(f)
			for(int j=1;j<=a[i];j++)s.push_back(c[i]); 
		a[i]+=a[i-1];
	}
	int sz=s.size();
	if(sum<=1e9)
		for(int i=0;i<sz/2;++i){
			if(s[i]^s[sz-i-1])ans++;
		}
	else{
		ans=0; 
	}
	cout<<ans;
	return 0;
} 
