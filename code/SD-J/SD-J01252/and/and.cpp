#include<bits/stdc++.h>
using namespace std;
int n,m,ar[200005]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1,cmp);
	cout<<ar[m];
}
