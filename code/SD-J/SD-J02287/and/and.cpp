#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=m;i>=1;i--){
		int sum=n;
		for(int j=n-m;j<=sum;j++){
			if(a[j]&a[j+1]>=ans){
				ans+=a[j]&a[j+1];
			}
		}
	}
	cout<<ans/2;
	//4 2 3 15 12 12
	//5 3 31 3 1 15 7
	return 0;
} 
