#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,  m;
	cin>>n>>m;
//	int x=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	/*	if(i==1){
			continue;
		}
		if(a[i]==a[i-1]){
			x=i;
		}*/
	}
	int q=1;
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			b[a[i]]++;
				
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	//zzy
	return 0;
} 
