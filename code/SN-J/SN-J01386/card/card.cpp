#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,a[200500];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1]; 
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
} 
