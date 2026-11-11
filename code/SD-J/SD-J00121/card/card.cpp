#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,a[500005],b[300005],m;
int ans[300005];
//int d[500005];
//struct stu {
//	int idx,val;
//}head[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=1;j<=n;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0){
				while(v.size()&&v.back()!=a[j])v.pop_back();
			}
			//v.push_back(a[j]);
			b[a[j]]=j;
		}
		for(int j=0;j<v.size();j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
