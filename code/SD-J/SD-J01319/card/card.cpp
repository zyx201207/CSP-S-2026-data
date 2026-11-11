#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans[300050];
vector<int>v[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);		
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int len=v[a[j]].size();
			for(int k=0;k<len;k++){
				if(v[a[j]][k]>=j){
					j=v[a[j]][len-1];
					break;
				}
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
