#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio();
	cin.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long L;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	long long ans=0,l=1,r=n,la=a[l],ra=a[r];
	while(l<r){
		if(c[l]==c[r]){
			int x=min(la,ra); 
			la-=x,ra-=x;
			if(la==0){
				l++,la=a[l];
			}
			if(ra==0){
				r--,ra=a[r];
			}
		}else{
			if(la<=ra){
				ans+=la;
				ra=ra-la;
				l++,la=a[l];
				if(ra==0){
					r--,ra=a[r];
				}
			}else{
				ans+=ra;
				la=la-ra;
				r--,ra=a[r];
				if(la==0){
					l++,la=a[l];
				} 
			}
		}
	}
	cout<<ans;
	return 0;
}

