#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[10000000];
int cf[10000000];
int ans=0;
bool check(int x,int i){
	    ans=0;
		for(int k=x;k>=1;k--){
			ans+=cf[i+k]*k;
		}
		if(ans<=m)return true;
		else{
		return false;		
		} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int mid;
		int l=1,r=n-i;
		int last;
		while(1){
			cout<<l<<" "<<r<<" ";
			ans=0;
			if(l>=r)break;
			 mid=(l+r)/2;
			if(check(mid,i)==true){
				l=mid+1;
				last=mid;
			}
			else{
				r=mid;
			}
			cout<<mid<<" "<<ans<<" ";
		}
		cout<<endl;
		maxn=max(maxn,last+1);
	}
	cout<<maxn;
	return 0;
}
