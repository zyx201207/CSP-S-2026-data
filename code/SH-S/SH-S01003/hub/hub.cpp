#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],p[100005];
int f(int t){
	for (int i=t;i<=n;i++){
		if (t*a[i]-(p[i]-p[i-t])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	int low=2,up=n;
	while(low<up){
		int mid=low+(up-low)/2;
		if (f(mid)==1){
			low=mid+1;
		}
		else{
			up=mid-1;
		}
	}
    if (f(low+1)==1){cout<<low+1<<endl;}
    else{
    	if (f(low)==1){cout<<low<<endl;}
    	else{
    		if (f(low-1)==1){cout<<low-1<<endl;}
    		else{
    			if (f(low-2)==1){cout<<low-2<<endl;}
			}
		}
	}
	return 0;
}
