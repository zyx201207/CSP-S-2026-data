#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct node{
	ll num;
	char v;
}s[N];
ll x,ans;
int n,len;
char a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>x>>a;
	s[++len]={x,a};
	for(int i=1;i<n;i++){
		cin>>x>>a;
		if(a==s[len].v)s[len].num+=x;
		else s[++len]={x,a};
	}
	int l=1,r=len;
	while(l<r){
		ll pos=min(s[l].num,s[r].num);
		if(s[l].v!=s[r].v)ans+=pos;
		s[l].num-=pos,s[r].num-=pos;
		if(s[l].num==0)l++;
		if(s[r].num==0)r--;
	}
	cout<<ans;
	return 0;
} 
