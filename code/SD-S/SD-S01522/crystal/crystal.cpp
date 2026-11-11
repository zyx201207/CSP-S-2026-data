#include <bits/stdc++.h>
using namespace std;
long long lose;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,m;
	long long ans=1;
	cin>>n>>m;
	lose=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	sort(b,b+n);
	if(b[0]+m<b[1]) cout<<"0";
	else if(b[0]+m==b[1]) cout<<"2";
	else {
		for(int j=0;j<n-1;j++){
			for(int i=0;i<=m;i++){
				if(a[j]+i==a[j+1]){
					lose-=i;
					if(lose<0) break;
					else{
						ans++;
						continue;
					}
				}
			}
		}
		cout<<ans;
	} 
	return 0;
} 
