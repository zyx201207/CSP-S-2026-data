#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x;
	cin>>x;
	int m;
	cin>>m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	sort(a+1,a+x+1,greater<int>());
	cout<<a[m];
}
