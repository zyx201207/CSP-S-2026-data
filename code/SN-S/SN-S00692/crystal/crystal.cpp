#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5000005];
ll n,m;
ll l=0,r=0,size=0/*´ú¼Û*/,ans=1;
ll daijia(){
	return (r-l+1)*(a[r+1]-a[r]);
}
void kuo(){
	while(1){
		if(r>=n-1)break;
		size+=daijia();
		if(size<=m){
			r++;
		}
		else{
			size-=daijia();
			break;
		}
	}ans=std::max(ans,r-l+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		std::cin>>a[i];
	}
	sort(&a[0],&a[n]);
	
	while(l<n){
		kuo();
		size-=a[r]-a[l];
		l++;
	}std::cout<<ans;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
