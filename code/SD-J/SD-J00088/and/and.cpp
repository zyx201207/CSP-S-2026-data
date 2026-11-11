#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,h;
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnt);
	h=a[1];
	for(int i=2;i<=m;i++){
		h=h&a[i];
	}
	cout<<h;
}
