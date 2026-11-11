#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,a[N],b[N],sum[N],lst[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		memset(b,0,sizeof b);
		memset(lst,0,sizeof lst);
		ll r=0;
		for(int j=i; j<=n; j++){
			if(lst[a[j]]!=0){
				for(int z=lst[a[j]]+1; z<=r; z++){
					lst[b[z]]=0;
				}
				r=lst[a[j]];
			}else{
				b[++r]=a[j];
				lst[a[j]]=r;
			} 
//			cout<<r<<" ";
		}
//		cout<<endl;
		for(int i=1; i<=r; i++){
//			cout<<b[i]<<" ";
			sum[b[i]]++;
		}
//		cout<<endl;
	}
	for(int i=1; i<=m; i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
