#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n,wum=0;
	while(l<r){
		if(c[l]==c[r]){
			int w=min(a[l],a[r]);
			a[l]-=w;
			a[r]-=w;
			if(a[l]==0)l++;
			if(a[r]==0)r--;	
		}else{
			int w=min(a[l],a[r]);
			wum+=w;
			a[l]-=w;
			a[r]-=w;
			if(a[l]==0)l++;
			if(a[r]==0)r--;	
		}
	}
	cout<<wum;
	return 0;
}