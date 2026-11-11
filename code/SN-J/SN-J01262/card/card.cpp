#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[300005],s[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=1;x<=n;x++){
		vector<int> v;
		for(int i=x;i<=n;i++){
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i]){
					while(v.size()!=j) v.pop_back();
				}
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++) s[v[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
