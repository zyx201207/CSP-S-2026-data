#include <bits/stdc++.h>
using namespace std;
long long ans,sl,a[600000],n,m,w,h,tans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n == 1){
		ans = 1;
	}
	sl = 1;
	h = 1;
	for(int i=2;i<=n;i++){
		 w = w+(a[i]-a[i-1])*sl;
		if(w<=m){
			sl++;
		}
		else{
			while(h<=i){
				w-=a[i]-a[h];
				h++;
				sl--;
				if(w<=m){
					sl++;
					break;
				}
			}
		}tans = max(sl,tans);
	}cout<<tans;
	
	return 0;
}



