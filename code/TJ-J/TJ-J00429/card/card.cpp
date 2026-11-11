#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>d1;
		d1.clear();
		for(int j=i;j<=n;j++){
			for(int k=0;k<d1.size();k++){
				if(a[j]==a[k]){
					if(k==0)d1.clear();
					else while(d1.size()>k)d1.pop_back();
					break;
				}
			}
			d1.push_back(a[j]);
		}
		for(int j:d1){
			for(int k=1;k<=m;k++){
				if(j==k)ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
