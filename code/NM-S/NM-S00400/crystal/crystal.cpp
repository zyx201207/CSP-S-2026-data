#include<bits/stdc++.h> 
using namespace std;
int n,m,cnt;
int a[1000000000010];
int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt+=a[i];
    }
    cout<<cnt/n;
	return 0;
}

