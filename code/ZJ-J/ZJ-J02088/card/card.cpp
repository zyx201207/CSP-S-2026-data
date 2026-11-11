#include<bits/stdc++.h>
using namespace std;
int n,m;
bool flag=1;
int a[500005],pst[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(a[i+1]>a[i]||i==n){
				ans[a[i]]=i;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
