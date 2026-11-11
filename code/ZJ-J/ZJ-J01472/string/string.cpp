#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[214514];
char c[214514];
int sum;
struct node{
	int l,r;
	char c;
};
vector<node>v,v2;
int cur;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum+=a[i];
	int l=1,r;
	for(int i=1;i<=n;i++){
		cur+=a[i];
		r=cur;
		v.push_back({l,r,c[i]});
		v2.push_back({sum-r+1,sum-l+1,c[i]});
		l=r+1;
	}
	reverse(v2.begin(),v2.end());
	int id=0;
	for(int i=0;i<v.size();i++){
		v[i].r=min(v[i].r,sum/2);
		while(id<v2.size()&&v[i].l<=v2[id].l&&v2[id].r<=v[i].r){
			ans+=(v2[id].r-v2[id].l+1)*(v2[id].c!=v[i].c);
			id++;
		}
		if(id<v2.size()){
			if(v2[id].c!=v[i].c){
				ans+=(v[i].r-v2[id].l+1);
			}
			v2[id].l=v[i].r+1;
		}
		if(v[i].r>sum/2){
			break;
		}
	}
	cout<<ans;
	return 0;
}
