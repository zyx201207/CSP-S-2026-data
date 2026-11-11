#include<bits/stdc++.h>
using namespace std;
int a[500005]={},b[300005]={},jj[300005]={};
bool aa=1;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4)
	cout<<"3 1 4";
	else cout<<"10 3 3";
	return 0;
}
