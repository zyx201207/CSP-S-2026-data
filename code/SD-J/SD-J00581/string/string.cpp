#include<bits/stdc++.h>
using namespace std;
long long c[200005];
char d[200005];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x;
	for(int i=1;i<=n;i++){
		char y;
		cin>>x>>y;
		c[i]=x;
		d[i]=y;
	}
	int l=1,r=n;
	unsigned long long ans=0;
	while(l<=r){
		if(d[l]==d[r]){
			if(c[l]>c[r]){
				c[l]-=c[r];
				c[r]=0;
				r--;
			}else if(c[l]<c[r]){
				c[r]-=c[l];
				c[l]=0;
				l++;
			}
			else{
				r--;
				l++;
			}
		}else{
			if(c[l]>c[r]){
				ans+=c[r];
				c[l]-=c[r];
				c[r]=0;
				r--;
			}else if(c[l]<c[r]){
				ans+=c[l];
				c[r]-=c[l];
				c[l]=0;
				l++;
			}
			else{
				ans+=c[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
 
