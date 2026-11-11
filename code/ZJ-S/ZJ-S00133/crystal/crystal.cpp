#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,n[500010],x,ma=1,y;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>n[i];
	}
	sort(n+0,n+a);
	for(int i=1;i<a;i++){
		y+=(i-x)*(n[i]-n[i-1]);
		while(y>b){
			y-=n[i]-n[x];
			x++;
		}
		ma=max(ma,i-x+1);
	}
	cout<<ma<<endl;
	return 0;
}
