#include<bits/stdc++.h>
using namespace std;
long long n,m,l,ans=0,k=0,t=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[m+5]={-1};
	for(int i=1;i<=n;i++){
		k=0;
		cin>>l;
		t=l;
		while(l!=0){
			if(l%2==1){
				k++;
			}
			l/=2;
		}
		for(int i=1;i<=m;i++){
			if(k>a[i]){
				if(k==a[i]){
					if(t>a[i]){
						a[i]=t;
						break;
					}
				}else{
					a[i]=t;
				    break;
				}
			}
		}
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
} 
