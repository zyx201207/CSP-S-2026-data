#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			sum^a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
		for(int i=2;i<=n;i++){
			if(a[i]>sum){
				sum=a[i];
			}
		}
		cout<<sum;
		return 0;
	}
	int cnt=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>cnt){
					cnt=a[i]&a[j];
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
