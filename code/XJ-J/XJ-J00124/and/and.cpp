#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];

int main(){
	//freopen(and.in;',''r';stdin);
	//freopen(and.out;',''w';stdout);
	
	int n,m,ans=0;cin>>n,m;
		for(int i=1;i<n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i]and a[j]>=ans){
					ans+=a[i]and a[j];
				}
			}
		}
	cout<<ans;
	return 0;
}
