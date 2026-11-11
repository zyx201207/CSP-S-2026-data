#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[10001],js,ans,k,zd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		a[i]=a[i]-a[i-1];
	}
	a[0]=0;
	for(int i=0;i<n;i++){
		js=0;k=0;ans=1;zd=1;
		for(int j=i+1;j<n;j++){
			k=j-i;
			for(int w=0;w<k;k++){
				js+=a[j+w];
			}
			if(js<=x){
				ans++;
			}else{
				break;
			}
			if(ans>zd){
				zd=ans;
			}
		}	
	}
	cout<<zd;
	return 0;
}
