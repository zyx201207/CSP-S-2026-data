#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<t[m]<<" ";
		}	
	return 0;
}
