#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		a[0]++;
		sort(a,a+n);
	}
	int ans=a[0];
	for(int i=0;i<n;i++){
		if(a[i]==a[0]){
			sum++;
		}else{
			break;
		}
	}
	cout<<sum;
	return 0;
} 
