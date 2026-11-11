#include<bits/stdc++.h>
using namespace std;
int a[500001],b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(a[n]==i){
			cout<<n<<" ";
			continue;
		}
		if(b[a[i]]>1){
			cout<<m<<" ";
		}
		else cout<<1<<" ";
	}
}
