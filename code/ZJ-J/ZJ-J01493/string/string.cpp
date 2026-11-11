#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	char c;
}cnt[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,all=0,f=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i].a>>cnt[i].c;
	}
	int l=1,r=n,ans=0;
	while(l!=r){
		if(cnt[l].c==cnt[r].c){
			if(cnt[r].a>cnt[l].a){
				cnt[r].a=cnt[r].a-cnt[l].a;
				cnt[l].a=0;
				l++;
			}
			else{
				cnt[l].a=cnt[l].a-cnt[r].a;
				cnt[r].a=0;
				r--;
			}
		}
		else{
			if(cnt[r].a>cnt[l].a){
				cnt[r].a=cnt[r].a-cnt[l].a;
				ans+=cnt[l].a;
				cnt[l].a=0;
				l++;
			}
			else{
				cnt[l].a=cnt[l].a-cnt[r].a;
				ans+=cnt[r].a;
				cnt[r].a=0;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}/*
2
1 a
2 b
2 b
abbbb
*/

