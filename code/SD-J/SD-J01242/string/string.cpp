#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,l=1,r,ans;
char b;
map<int,pair<int,char> >c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		c[i]={a,b};
	}
	while(l<r){
		char o=c[l].second,p=c[r].second;
		int m=c[l].first,n=c[r].first;
		if(o==p){
			if(m>n){
				c[l].first=c[l].first-n;
				r--;
			}else if(n>m){
				c[r].first=c[r].first-m;
				l++;
			}else{
				l++,r--;
			}
		}else{
			if(m>n){
				ans+=n;
				c[l].first=c[l].first-n;
				r--;
			}else if(n>m){
				ans+=m;
				c[r].first=c[r].first-m;
				l++;
			}else{
				ans+=m;
				l++,r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

