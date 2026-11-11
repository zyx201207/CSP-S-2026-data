#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
bool cmp(int x,int b){
	return x>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp); 
	int cnt=a[1];
	for(int i=2;i<=m;i++){
		cnt^=a[i];
	}
	cout<<cnt;
return 0;
}

