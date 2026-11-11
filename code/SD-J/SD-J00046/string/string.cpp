#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int x=a[1],y=a[n];
	for(int i=1,j=n;i<j;){
		int ans=min(x,y);
		x-=ans;y-=ans;
		if(c[i]!=c[j]){
			sum+=ans;
		}
		if(x==0)x=a[++i];
		if(y==0)y=a[--j];
	}
	cout<<sum<<endl;
	return 0;
}
