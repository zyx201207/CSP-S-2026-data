#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long h=0,x=0,xh=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			h+=(a[i]-a[j]);
			x++;
		}
		if(h>m){
			int t=1;
			while(h>m){
				h-=(a[i]-a[t]);
				t++;
				x--;
			}
		}
		if(x>xh) xh=x;
		x=0;
		h=0;
	}
	cout<<xh;
	return 0;
} 
