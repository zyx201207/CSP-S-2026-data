#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m,k=1,co=0;
	int a[99999999];
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n;i>=1;i--){
		c[k]=a[n]-a[n-1];
		k++;
	}
	for(int i=0;i<n;i++){
		if(m>a[i+1]-a[i]){
			m-=a[i+1]-a[i];
			a[i]=a[i+1];
			for(int j=i;j>0;j--){
				if(a[j]>a[j-1]&&j>=1){
					if(a[j]-a[j-1]<m){
						a[j-1]=a[j];
					}
				}
			}
		}
	}
	for(int i=0;i>n;i++){
		if(a[i]==a[i+1]){
			co++;
		}
	}
	cout<<co;
	return 0;
}
