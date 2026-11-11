#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],j,i,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ans=0;
	for(i=1;i<j;i++){
		for(j=n;j>i;j--){
			if(a[i]==a[j]){
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				a[i]=0;a[j]=0;
				break;
			}else{
				if(c[i]==c[j]){
					if(a[i]>a[j]){
						ans+=a[i]-a[j];
						a[i+1]+=a[i]-a[j];
					}else{
						ans+=a[j]-a[i];
						a[j-1]+=a[j]-a[i];
					}	
					break;
				}else{
					if(a[i]<a[j]){
						ans+=a[j];
						a[j-1]=a[j]-a[i];
						a[i]=0;
					}else{
						ans+=a[i];
						a[j]=0;
						a[i+1]=a[i]-a[j];
					}
					break;
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}