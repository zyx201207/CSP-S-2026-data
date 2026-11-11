#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,a[500010],b[500010],ans[300010],sum;
bool pd(int x){
	for(int i=1;i<=t;i++)
		if(b[i]==a[x]) return 0;
	return 1;
}
void gai(int x){
	for(int i=1;i<=t;i++)
		if(b[i]==a[x]){
			t=i;
			break;
		}
}
bool pd2(int x){
	int l,r,mid;
	l=1;r=t;
	while(l<=r){
		mid=(l+r)/2;
		if(b[mid]==a[x]) return 0;
		else if(b[mid]>a[x]) r=mid-1;
		else l=mid+1;
	}
	return 1;
}
void gai2(int x){
	int l,r,mid;
	l=1;r=t;
	while(l<=r){
		mid=(l+r)/2;
		if(b[mid]==a[x]){
			t=mid;
			break;
		}
		else if(b[mid]>a[x]) r=mid-1;
		else l=mid+1;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i+1]) sum++;
	if(sum==n-1){
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=i;j<=n;j++){
				if(pd2(j)){
					b[++t]=a[j];
				}
				else gai2(j);
			}
			for(int i=1;i<=t;i++)
				ans[b[i]]++;
		}
		for(int j=1;j<=m;j++)
			cout<<ans[j]<<" ";
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			t=0;
			for(int j=i;j<=n;j++){
				if(pd(j)){
					b[++t]=a[j];
				}
				else{
					gai(j);
				}
			}
			for(int i=1;i<=t;i++)
				ans[b[i]]++;
		}
		for(int j=1;j<=m;j++)
			cout<<ans[j]<<" ";		
	}
	return 0;
}