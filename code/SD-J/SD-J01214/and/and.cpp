#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a[200005];
	int n,m,max=0;
	cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	for(int i =0;i<n-m+1;i++){
		int sum=a[i];
		for(int j =i+1;j<=m;j++){
			sum=sum&a[j];
		}
		if(sum>max){
			max=sum;
		}
	}
	cout<<max;
}  
