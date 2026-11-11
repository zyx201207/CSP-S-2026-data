#include<bits/stdc++.h>
#define int long long
using namespace std;
char ch[200005];
int n,s[200005],ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]>s[r]){
			s[l]-=s[r];
			if(ch[l]!=ch[r]){
				ans+=s[r];
			}
			r--;
		}
		else if(s[l]<s[r]){
			s[r]-=s[l];
			if(ch[l]!=ch[r]){
				ans+=s[l];
			}
			l++;
		}
		else{
			if(ch[l]!=ch[r]){
				ans+=s[l];
			}
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}

