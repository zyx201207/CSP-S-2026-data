#include<bits/stdc++.h>
using namespace std;
#define int long long
int l[500002];
int ls[500002];
int n,m;
bool check(int s,int e){
	int cha=l[e]*(e-s+1)-(ls[e]-ls[s-1]);
	if (cha>m){
		return 0;
	}
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	ls[0]=0;
	for (int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	for (int i=1;i<=n;i++){
		ls[i]=ls[i-1]+l[i];
	}
	int ans=1;
	for (int i=1;i<=n;i++){
		int st=i;
		int l=1,r=i,mid;
		while (l<=r){
			mid=(l+r)/2;
			if (check(mid,i)){
				st=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if ((i-st+1)>ans){
			ans=(i-st+1);
		}
	}
	cout<<ans;
	return 0;
} 
