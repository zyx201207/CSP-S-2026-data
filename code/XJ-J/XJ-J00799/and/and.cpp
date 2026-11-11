#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
int arr[200];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	int ans;
	cin>>n>>m;
	for(int a=1;a<=n;a++)
		cin>>arr[a];
	sort(arr+1,arr+n+1);
	cout<<(arr[n]&arr[n-1]);
	return 0;
}