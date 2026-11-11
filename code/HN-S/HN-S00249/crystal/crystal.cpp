#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],up,now[555555];  
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		a[i]=abs(a[i]);
	}
	if(n<=5000) sort(a+1,a+1+n);
	else sort(a+1,a+5001);
	for(int i=1;i<=n;i++){
		up+=a[i];
		now[i]=abs(a[i])*i-up;
		if(now[i]>m){
			cout <<i-1;
			break;
		}
	}
	return 0;
}
