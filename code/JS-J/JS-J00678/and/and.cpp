#include<bits/stdc++.h>
using namespace std;
int a[200007];
int m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int max=0;
		for(int i=0;i<n;i++){
			if(a[i]>max) max=a[i];
		}
		cout<<max;
		return 0;
	}else if(n==m){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if((a[i]&a[j])>max){
					max=a[i]&a[j];
				}
			}
		}
		cout<<max;
		return 0;
	}
}
