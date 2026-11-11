#include<bits/stdc++.h>
using namespace std;
struct Node{
	char c;
	long long sum;
}a[200005];
long long ans,n,l,cnt,r,k;
bool f=false;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
		ans+=a[i].sum;
	}
	if(ans%2==0) f=true;
	ans/=2;
	while(a[l].sum<=ans){
		ans-=a[l].sum;
		l++;
	}
	if(ans){
		for(int i=n+1;i>=l+2;i--){
			a[i].sum=a[i-1].sum;
			a[i].c=a[i-1].c;
		}
		a[l+1].c=a[l].c;
		if(f) a[l+1].sum=a[l].sum-ans-1;
		else a[l+1].sum=a[l].sum-ans;
		a[l].sum=ans;
		k=l;
		l=1;
		r=n+1;
	}else {
		l--;
		k=l;
		l=1;
		r=n;
	}	
	while(l<=k&&r>k){
		if(a[l].c!=a[r].c){
			if(a[l].sum>=a[r].sum){
				cnt+=a[r].sum;
				a[l].sum-=a[r].sum;
				r--;
			}else{
				cnt+=a[l].sum;
				a[r].sum-=a[l].sum;
				l++;
			}
		}else{
			if(a[l].sum>=a[r].sum){
				a[l].sum-=a[r].sum;
				r--;
			}else{
				a[r].sum-=a[l].sum;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}