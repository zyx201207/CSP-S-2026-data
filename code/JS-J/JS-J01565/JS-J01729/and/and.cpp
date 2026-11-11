#include<iostream>
#include<algorithm>
int a[100005];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	else if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		return 0;
	}
    else if(m==2){
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>ans){
					ans=a[i]&a[j];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
