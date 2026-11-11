#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e5+10;
ll n,m,a[N],ans,maxx;
bool cmp(int x,int y){
	if(x<y){
		return 0;
	}
	else{
		return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int l=1;l<=n;l++){
		ans=a[l];
		for(int r=l+1;r-l+1<=m;r++){
			ans=ans&a[r];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx; 
	return 0;
} 
