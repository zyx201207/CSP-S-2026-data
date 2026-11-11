#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
struct Node{
	ll a;
	char c;
}s[N+10];
int n;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	ll res=0;
	int l=1,r=n;
	while(l<=r){
		if(s[l].c==s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
			}else{
				l++,r--;
			}
			continue;
		}
		if(s[l].a>s[r].a){
			res+=s[r].a;
			s[l].a-=s[r].a;
			r--;
		}else if(s[l].a<s[r].a){
			res+=s[l].a;
			s[r].a-=s[l].a;
			l++;
		}else{
			res+=s[l].a;
			l++,r--;
		}
	}
	cout<<res;
	return 0;
}
