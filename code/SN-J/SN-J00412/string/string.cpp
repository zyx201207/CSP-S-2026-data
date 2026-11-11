#include<bits/stdc++.h>
using namespace std;
long long n,k;
struct str{
	int x;
	char y;
}s[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].x>>s[i].y;
	k=n;
	for(int i=1;i<=k;){
		if(s[i].y!=s[k].y)ans+=min(s[i].x,s[k].x);
		if(s[i].x==s[k].x){
			i++;
			k--;
		}
		else if(s[i].x>s[k].x){
			s[i].x-=s[k].x;
			k--;
		}
		else{
			s[k].x-=s[i].x;
			i++;
		}
	}
	cout<<ans;	
	return 0;
}
