#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	int x=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==0){
		for (int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				x++;
			}
		}
		cout<<x;
	}
	return 0;
}
