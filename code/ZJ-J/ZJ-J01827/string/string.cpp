#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len,ans;
string s;
struct node{
	int a;
	char c;
}b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		len+=b[i].a;
	}
	int l=1;
	int r=len;
	int lpos=1;
	int rpos=n;
	while(l<r){
		if(b[lpos].a>b[rpos].a){
			if(b[lpos].c!=b[rpos].c){
				ans+=b[rpos].a;
				
			}
			l+=b[rpos].a;
			r-=b[rpos].a;
			b[lpos].a-=b[rpos].a;
			rpos--;
		}
		else if(b[lpos].a<b[rpos].a){
			if(b[lpos].c!=b[rpos].c){
				ans+=b[lpos].a;
				
			}
			l+=b[lpos].a;
			r-=b[lpos].a;
			b[rpos].a-=b[lpos].a;
			lpos++;
		}
		else{
			if(b[lpos].c!=b[rpos].c){
				ans+=b[lpos].a;
			}
			l+=b[lpos].a;
			r-=b[lpos].a;
			lpos++;
			rpos++;
		}
	}
	cout<<ans;
}