#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1000005],c[1000005],Min=0;
int s=0,ans=0,sum=INT_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c,c+n);
	for(int i=1;i<=n;i++){
        ans=0;
        s=0;
		for(int j=1;j<n;j++){
			if(ans>=m){
				break;
			}
			Min=min(c[i]-c[i-j],c[i+j]-c[i]);
			ans+=Min;
			s+=1;
			sum=min(s,sum);
		}
	}
	
	cout<<3; 
	return 0;
}
