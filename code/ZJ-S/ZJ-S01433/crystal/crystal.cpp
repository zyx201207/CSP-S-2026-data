#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,x,w,h;
long long a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	if(m>2000000000000){
		cout<<n;
		return 0;
	}
	for(i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	w=0;
	for(i=1;i<n;i++){
		x=1;
		h=m;
		for(j=i-1;j>=0;j--){
			if(h>=a[i]-a[j]){
				h-=(a[i]-a[j]);
				x++;	
			}else	break;
		}
		if(x>w)	w=x;
	}
	cout<<w;
	return 0;
}
