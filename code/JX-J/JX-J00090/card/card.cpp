#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int t[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		set<int> ss;
		for(int j=i;j<=n;j++){
			ss.insert(a[j]);
		}
		t[ss.size()]++;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
