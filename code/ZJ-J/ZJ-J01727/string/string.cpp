#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	char x;
	int num;
}p[200005];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int inend=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].num>>p[i].x;
		inend+=p[i].num;
	}
	int ans=0,l=1,r=n;
	while(l<=r){
	   	if(p[l].num>p[r].num){
	   	   	if(p[l].x!=p[r].x){
	   	   		ans+=p[r].num;
			}
			p[l].num-=p[r].num;
			p[r].num=0;
			r--;
		}
		else if(p[l].num==p[r].num){
			if(p[l].x!=p[r].x){
				ans+=p[l].num;
			}
			p[l].num=0;p[r].num=0;
			l++;r--;
		}
		else{
			if(p[l].x!=p[r].x){
				ans+=p[l].num;
			}
			p[r].num-=p[l].num;
			p[l].num=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
