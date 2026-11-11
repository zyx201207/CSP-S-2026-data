#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
struct node{
	ll a;
	char c;
}s[200005];
ll sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	}
	ll l=1,r=t,cntl=1,cntr=sum,ans=0;
	while(l<r&&cntr-cntl>=s[l].a&&cntr-cntl>=s[r].a){
		if(s[l].c!=s[r].c){
			ans+=min(s[l].a,s[r].a);
			
		}
		if(s[l].a<s[r].a){
			s[r].a-=s[l].a;
			cntr-=s[l].a;
			s[l].a=0;
		}
		else{
			s[l].a-=s[r].a;
			cntl+=s[r].a;
			s[r].a=0;
		}
		if(s[l].a==0){
			l=l+1;
		}
		if(s[r].a==0){
			r=r-1;
		}
	}
	cout<<ans;
	return 0;
}
