#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct str{
	char val;
	int pos;
}a[200010];
int findpos(int x){
	int ans=-1;
	x=a[n].pos-x+1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid].pos>=x)
			ans=mid,r=mid-1;
		else
			l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].pos>>a[i].val,a[i].pos+=a[i-1].pos;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i-1].pos<(a[n].pos+1)/2&&a[i].pos>(a[n].pos+1)/2){
			int r=findpos(a[i-1].pos+1),l=findpos((a[n].pos+1)/2);
			while(l<=r)
				ans+=(a[l].val!=a[i].val)*
					(min(a[n].pos-a[i-1].pos,a[l].pos)-
						max(a[n].pos-(a[n].pos+1)/2+1,a[l-1].pos+1)+1ll),l++;		
		}
		if(a[i].pos<=(a[n].pos+1)/2){
			int r=findpos(a[i-1].pos+1),l=findpos(a[i].pos);
			while(l<=r)
				ans+=(a[l].val!=a[i].val)*
					(min(a[n].pos-a[i-1].pos,a[l].pos)-
						max(a[n].pos-a[i].pos+1,a[l-1].pos+1)+1ll),l++;
		}
	}
	cout<<ans;
	return 0;
}
