#include<bits/stdc++.h>
//#define int long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=1;
		for(int j=1;j<=31;j++){
			if(a[i]==t)	a[i]=0;
			t*=2;
		}
	} 
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	cout<<a[m];
	return 0;
}
