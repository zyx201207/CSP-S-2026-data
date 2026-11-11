//T3
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,mx=-0x7fffffff;
array<int,N>a;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
	}else if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++){
			mx&=a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}else{
		mx=rand();
	}
	cout<<mx;
	return 0;
}
