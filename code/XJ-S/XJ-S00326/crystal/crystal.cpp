#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[500005],t[500005],d[500005];
int n,m,ans=0;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    	cin>>a[i];
	
	sort(a+1,a+1+n);
	
	t[1]=0;
	for(int i=2;i<=n;i++)
    	t[i]=a[i]-a[i-1];
/*
    for(int i=1;i<=n;i++){
    	cout<<t[i]<<" ";
	}
	cout<<endl;
*/
    for(int i=2;i<=n;i++)
    	d[i]=(i-1)*t[i]+d[i-1];
    
    for(int i=2;i<=n;i++)
    	t[i]+=t[i-1];
    
    
/*    
    for(int i=1;i<=n;i++){
    	cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
    	cout<<d[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
    	cout<<t[i]<<" ";
	}
	cout<<endl;
*/
	for(int i=2;i<=n;i++){
		//cout<<i<<endl;
		if(d[i]<=m)
			ans=max(ans,i);
		else{
			int l=0,r=i;
			int mid=(l+r)/2;
			while(l<r){
				//cout<<l<<" "<<r<<" "<<mid<<" "<<d[i]-d[mid]-(t[i]-t[mid])*mid*r<<endl;
				
				if(d[i]-d[mid]-(t[i]-t[mid])*mid>m)
					l=mid+1;
				
				else
					r=mid;
					
				mid=(l+r)/2;
			}
			ans=max(ans,i-mid);
		}
	}
	
	cout<<ans;
	
	return 0;
}
