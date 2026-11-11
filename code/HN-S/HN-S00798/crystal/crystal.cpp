#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t=0;
int a[1000001];
int d[1000001];
int f[1000001];
int ma=INT_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=(a[i]-a[i-1])*t+d[i-1];
		t++;
		if(d[i]>=m){
			while(d[i]>m){
				d[i]-=a[i]-a[i-t+1];
				t--;
			}
		}
		ma=max(ma,t);
	}
	cout<<ma;
	return 0;
} 
/*
Oct31==Dec25?
6 7
2 4 3 4 6 3
*/
