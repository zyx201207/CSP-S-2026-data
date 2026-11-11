// 张杲楹 陕西省西安爱知中学 SN-J00690 
#include <bits/stdc++.h>
using namespace std;
int a[100000000];
int i=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[i-2];
	return 0;
}
