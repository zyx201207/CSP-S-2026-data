#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b=1,c[500005];
	map<int,int> ans;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			b=0;
		}
	}
	if(b==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=m;j++){
				c[j]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
