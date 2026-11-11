#include<bits/stdc++.h>
using namespace std;
int n,a[100005],m,c[100005],b[100005];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
	    b[i]+=c[i];
	}
	for(int i=1;i<=n;i++){
		int l=i+1,r=m-1,mid,ans=0;
		while(l<r){
			mid=(l+r)/2;
			if(b[mid]-b[i]>=m){
				r=mid+1;
			}
			else{
			    ans=max(ans,(mid-i)+1);
				l=mid+1;												
			}
		}
	cout<<ans<<endl;
    return 0;
    }
}
