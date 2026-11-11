#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n;int a[200005];
bool count1(int a){
	int ans=0;
	while(a){
		ans++;
		if(ans>1) return 0;
		a&=a-1;
	}return ans==1;
}
int dgF(int now,int xb,int sx){
	if(sx==0) return now;
	if(now==0) return 0;
	if(n-xb-1<sx) return 0;
	int ans=0;
	for(int i=xb+1;i<n;i++){
		ans=max(ans,dgF(now&a[i],i,sx-1));
		if(count1(a[i]+1)) break;
	}
	return ans;
}
bool tmp(int a,int b){return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int mx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,tmp);
	for(int i=0;i<n;i++){
		mx=max(mx,dgF(a[i],i,m-1));
		if(count1(a[i]+1)){
			//cout<<a[i];
			break;
		}
	}
	cout<<mx;
	return 0;
}

