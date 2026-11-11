#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],m,maxx,yu;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],maxx=max(a[i],maxx);
		if(i==1){
			yu=a[i];
		}else{
			yu=(yu&a[i]);
		}
	} 
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<yu;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					yu=max(yu,(a[i]&a[j]));
				}
			}
		}
		cout<<yu;
		return 0;
	}
	if(m==n-1){
		maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,(yu|a[i]));
		}
		cout<<maxx;
		return 0;
	}
	cout<<a[n];
	return 0;
}
