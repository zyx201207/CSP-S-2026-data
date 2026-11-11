#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct zf{
	int a;
	char c;
}s[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c!=s[r].c){
			if(s[l].a<s[r].a) {
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
			else{
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
		}
		else {
			if(s[l].a<s[r].a) {
				s[r].a-=s[l].a;
				l++;
			}
			else{
				s[l].a-=s[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
