#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],mx=-1,mn=INT_MAX; 
bool cmp(long long int x,long long int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),mn=min(mn,a[i]);
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<mx;
		return 0;
	}
	else{
		cout<<a[m];
		return 0;
	}
	return 0;
} 
