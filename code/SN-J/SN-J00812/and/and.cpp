//刘雨辰 SN-J00812 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,a[2001],b=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b=max(b,a[i]);
	}
	cout<<b;
	
	return 0;
}
