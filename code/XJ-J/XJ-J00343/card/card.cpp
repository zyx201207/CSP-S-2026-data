#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ans[i]++;
			continue;
		}
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				ans[i]++;
				break;
			}
			if(a[j]==i){
				ans[i]++;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
