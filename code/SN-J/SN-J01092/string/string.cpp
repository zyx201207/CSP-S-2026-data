#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
struct Str{
	int cnt;
	char c;
}s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].cnt>>s[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].cnt==s[r].cnt){
				l++;r--;
			}else if(s[l].cnt>s[r].cnt){
				s[l].cnt-=s[r].cnt;
				r--;
			}else{
				s[r].cnt-=s[l].cnt;
				l++;
			}
		}else{
			ans+=min(s[l].cnt,s[r].cnt);
			if(s[l].cnt==s[r].cnt){
				l++;r--;
			}else if(s[l].cnt>s[r].cnt){
				s[l].cnt-=s[r].cnt;
				r--;
			}else{
				s[r].cnt-=s[l].cnt;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
