#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	int x;
	cin>>x;
	for(int i=1;i<=m;i++){
		if(i==x){
			cout<<n<<" ";
			continue;
		}
		cout<<a[i]<<" ";
	}
	return 0;
}

