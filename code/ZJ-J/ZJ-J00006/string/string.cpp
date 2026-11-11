#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m;
struct node{
	int len;
	char c;
}e[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int len;
		char c;
		cin>>len>>c;
		if(c==e[m].c)e[m].len+=len;
		else e[++m]={len,c};
	}
	n=m;
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(e[l].c!=e[r].c){
			if(e[l].len>e[r].len){
				ans+=e[r].len;
				e[l].len-=e[r].len;
				r--;
			}else if(e[l].len==e[r].len){
				ans+=e[l].len;
				l++,r--;
			}else{
				ans+=e[l].len;
				e[r].len-=e[l].len;
				l++;
			}
		}else{
			if(e[l].len>e[r].len){
				e[l].len-=e[r].len;
				r--;
			}else if(e[l].len==e[r].len){
				l++,r--;
			}else{
				e[r].len-=e[l].len;
				l++;
			}
		}
	}
	cout<<ans<<"\n";
}
