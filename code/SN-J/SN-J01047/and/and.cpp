#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
const int maxn=200005;
int a[maxn]; 
vector<int> v;
void dk(int p,int o){
	if(o==m){
		int res=v[0];
		for(int i=1;i<v.size();i++){
			res&=v[i];
		}
		ans=max(ans,res);
		return;
	}
	if(p==n+1)return;
	v.push_back(a[p]);
	dk(p+1,o+1);
	v.pop_back();
	dk(p+1,o);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dk(1,0);
	cout<<ans;
} 
