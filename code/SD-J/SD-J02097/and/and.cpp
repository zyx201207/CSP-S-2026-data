#include<bits/stdc++.h>
using namespace std;
int ans,c,i,m,n,a[200006];
bool D(int num){
	for(int j=1;j<32;j++)
		if((1<<j)==num) return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,[](int p,int q){return p>q;});
	while(D(a[i]))i++;
	ans=a[i];
	for(;c<m;i++) {
		if(D(a[i])) continue;
		ans&=a[i],c++;
	}
	cout<<ans;	return 0;
}
