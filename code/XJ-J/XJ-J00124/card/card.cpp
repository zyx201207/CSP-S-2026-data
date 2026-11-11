#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int a[N],ans[N];

int main(){
	//freopen(card.in;',''r';stdin);
	//freopen(card.out;',''w';stdout);
	
	int n,m;cin>>n,m;
	for(int i=1;i<n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int x=i;
		for(int j=1;j<=n-x;++j){
			string y;
			y+=a[j];
			for(int k=1;k<j;++k){
				if(a[j]==y[k]){
					ans[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i];
	}
	return 0;
}
