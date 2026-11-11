#include<bits/stdc++.h>
#define int long long
#define go(x)(cout<<x<<'\n',void())
#define go1(x)(cout<<x<<' ',void())
#define vi vector<int>
#define in(x)(cin>>x,void())
#define in1(x,y)(cin>>x>>y,void())
#define in2(x,y,z)(cin>>x>>y>>z,void())
#define pb push_back
#define vc vector<char>
using namespace std;
void solve(){
	int a,ans=0;
	in(a);
	char b[a+1];
	int ma[a+1];
	for(int i=0;i<a;i++) in1(ma[i],b[i]);
	int r=a-1,l=0;
	while(r>l){
		if(b[l]!=b[r]){
			if(ma[l]>ma[r]){
				ans+=ma[r];
				ma[l]-=ma[r];
				ma[r]-=ma[r];
			}
			else{
				ans+=ma[l];
				ma[r]-=ma[l];
				ma[l]-=ma[l];
			}
		}
		else{
			if(ma[l]>ma[r]){
				ma[l]-=ma[r];
				ma[r]-=ma[r];
			}
			else{
				ma[r]-=ma[l];
				ma[l]-=ma[l];
			}
		}
		if(ma[r]==0) r--;
		if(ma[l]==0) l++;
	}
	go(ans);
	return ;

}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}
