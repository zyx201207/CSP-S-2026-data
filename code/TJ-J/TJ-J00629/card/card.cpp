#include<bits/stdc++.h>
using namespace std;
int n,m;int a[200005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=f){
			f=a[i];
			cout<<i-1<<" ";
		}
	}
	return 0;
}
