#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500033],ans;
int d(int x,int y){
	return abs(x-y);
}
signed main(){
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	cin>>n>>m;
	int l=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int p=1,q=-1,t=1;
		while(true){
			if(i+p<=n&&i+q>=1){
				if(d(a[i+p],a[i])<=d(a[i+q],a[i])){
					if(l<d(a[i+p],a[i])) break;
					l-=d(a[i+p],a[i]);
					p++;t++;
				}
				else{
					if(l<d(a[i+q],a[i])) break;
					l-=d(a[i+q],a[i]);
					q--;t++;
				}
			}
			else if(i+p>n){
				if(l<d(a[i+q],a[i])) break;
					l-=d(a[i+q],a[i]);
					q--;t++;
			}
			else if(i+q<1){
				if(l<d(a[i+p],a[i])) break;
					l-=d(a[i+p],a[i]);
					p++;t++;
			} 
			else break;
		}
		ans=max(ans,t);
		l=m;
	}
	cout<<ans;
	return 0;
} 
