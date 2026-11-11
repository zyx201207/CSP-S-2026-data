#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
ll n,a[200010];
char ch[200010];
ll cnt;
ll pre[200010];
ll l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>ch[i];
	}
	l=1,r=n;
	cnt=0;
	while(l<=r){
		if(ch[l]!=ch[r]) cnt+=min(a[l],a[r]);
		if(a[l]-a[r]>0){
			a[l]-=a[r];
			l--;
		}else if(a[r]-a[l]>0){
			a[r]-=a[l];
			r++;
		}
		l++,r--;
	} 
	cout<<cnt;
	return 0;
} 
