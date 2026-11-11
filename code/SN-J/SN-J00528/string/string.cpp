#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e7+10;
char k[N];
int n[N],sum,q,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n[i]>>k[i];
		sum+=n[i];
	}
	int l=1,r=q;
	for(int i=1;i<=sum/2;i++){
		int minn=min(n[l],n[r]);
		n[l]-=minn,n[r]-=minn;
		if(n[l]==0){
			l++;
		}
		if(n[r]==0){
			r--;
		}
		if(k[l]!=k[r]){
			cnt+=minn;
		}
	}
	cout<<cnt;
	return 0; 
}
