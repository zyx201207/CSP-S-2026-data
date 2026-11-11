#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long awy;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	awy=(arr[0] & arr[1]);
	for(int i=2;i<m;i++){
		awy=(awy & arr[i]);
	}
	cout<<awy;
	return 0;
}
