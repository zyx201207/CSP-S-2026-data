#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
long long n,ans;
struct node{
	int n;
	char let;
}s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].n>>s[i].let;
	for(int i=1,j=n;i<j;){
		int x=min(s[i].n,s[j].n);
		ans+=x*(s[i].let!=s[j].let);
		s[i].n-=x;
		s[j].n-=x;
		if(s[i].n==0)i++;
		if(s[j].n==0)j--;
	}
	cout<<ans;
	return 0;
}