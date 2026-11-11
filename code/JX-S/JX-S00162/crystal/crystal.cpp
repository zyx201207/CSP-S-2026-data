#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=-1,ans1,x,l,r;
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans1=1;
		x=m,l=i-1,r=i+1;
		while(x>=0){
			int left=abs(a[i]-a[l]),right=abs(a[r]-a[i]);
			if((x-left<0 and l>=1) or (x-right<0 and r<=n) or (l<1 and r>n)) break;
			if((left<right and l>=1 and r<=n) or r>n){
				x-=left;
				ans1++;
				l--;
			}else if(r<=n){
				x-=right;
				ans1++;
				r++;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
