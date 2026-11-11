#include<bits/stdc++.h>
using namespace std;
int a1[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a1[i];
	}
	sort(a1,a1+n);
	reverse(a1,a1+n);
	cout<<a1[m-1];
}
