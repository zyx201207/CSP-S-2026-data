#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct Node{
	int a;
	char c;
}t[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    int mx=0;
    for(int i=1;i<=n;i++){
    	cin>>t[i].a>>t[i].c;
    	mx=max(mx,t[i].a);
	}
	if(mx<=500){
		for(int i=1;i<=n;i++){
	    	cin>>t[i].a>>t[i].c;
	    	mx=max(mx,t[i].a);
	    	for(int j=0;j<t[i].a;j++){
	    		s+=t[i].c;
			} 
		}
		int l=0,r=s.size()-1,ans=0;
		for(int i=0;i<s.size()/2;i++){
			if(s[l]!=s[r]){
				ans++;
			}
			l++,r--;
		}
		cout<<ans;
		return 0;
	}
	int l=1,r=n;
	int ans=0;
	for(int i=1;i<=n/2;i++){
		if(t[l].c!=t[r].c){
			if(t[l].a==t[r].a){
				ans+=t[l].a;
			}
			else{
				ans+=max(t[l].a,t[r].a);
			}
		}
		else{
			if(t[l].a!=t[r].a){
				ans+=abs(t[l].a-t[r].a);
			}
		}
	}
	cout<<ans;
	return 0;
}
