#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int a[N],d1[N],d2[N],d[N],n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int flag=1,k=0;
	for(int i=2;i<=n;i++){
		d1[i]=a[i]-a[i-1];
		k=d1[i];
		if(d1[i]!=d1[i-1]){
			flag=0;
		}
	}
	if(flag){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			sum+=k*i;
			if(sum>m){
				break;
			}
			cnt++;
		}
		cout<<cnt+1<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			d[i]=d[i-1]+(i-1)*d1[i];
		}
		for(int l=n;l>=1;l--){
			for(int i=1;i<=n-l+1;i++){
				int s=i,e=i+l-1;
				int cost=d[e]-(e-l)*(a[e]-a[s]);
				if(cost<=m){
					cout<<l<<endl;
					return 0;
				}
			} 
		}
	}
	return 0;
} 
