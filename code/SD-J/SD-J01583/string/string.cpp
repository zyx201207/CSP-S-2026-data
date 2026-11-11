#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
struct node{
	int a;
	char c;
}t[N];
int l,r;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		cin>>t[i].c;
	}
	l=1,r=n;
	while(l<r){
		if(t[l].a>t[r].a){
			if(t[l].c!=t[r].c) cnt+=t[r].a;
			t[l].a-=t[r].a;
			t[r].a=0;
			r--;
		}
		else if(t[l].a<t[r].a){
			if(t[l].c!=t[r].c) cnt+=t[l].a;
			t[r].a-=t[l].a;
			t[l].a=0;
			l++;
		}
		else if(t[l].a==t[r].a){
			if(t[l].c!=t[r].c) cnt+=t[l].a;
			t[l].a=0;
			t[r].a=0;
			l++,r--;
		}
	}
	cout<<cnt;
	return 0;
}
