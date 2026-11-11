//kao hao:SH-J00674   xing ming:wang ge   xue xiao:yan an pei zhi zhong xue
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int arr[200010];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int o= 1;
	for(int i = 0;i<n;i++){
		o = o and arr[i];
	}
	cout<<o;
	return 0;
} 
