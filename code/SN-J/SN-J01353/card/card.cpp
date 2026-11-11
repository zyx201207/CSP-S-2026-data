#include<bits/stdc++.h>
using namespace std;
long long a[500005],end[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		end[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=end[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";

	return 0;
}

