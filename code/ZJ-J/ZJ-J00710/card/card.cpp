#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int n,m;
int a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> ve;
		for(int j=i;j<=n;j++){
			int x=a[j];
			for(int k=0;k<ve.size();k++){
				if(ve[k]==x){
					int y=ve.size()-k;
					while(y--) ve.pop_back();
				}
			}
			ve.push_back(x);
		}
		for(auto c:ve){
			ans[c]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}