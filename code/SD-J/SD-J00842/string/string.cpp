#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char ch[200005];
map <char,int> need;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0,mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		len+=a[i];
		mx=max(mx,a[i]);
	}
	if(mx<=12345){
		string s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++)
				s+=ch[i];
		}	
		int ans=0;
		for(int i=0,j=len-1;i<=j;i++,j--){
			if(s[i]!=s[j])
				ans++;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n/2;i++)
		need[ch[i]]+=a[i];
	for(int i=1,j=n;i<=j;i++,j--){
		a[j]-=(need[ch[j+1]]-a[j+1]);
		if(ch[i]==ch[j]) need[ch[i]]-=a[j];
	}	
	for(int i=1;i<=n/2;i++)
		ans+=need[ch[i]];
	cout<<max(ans,0LL);	
	return 0;
}
