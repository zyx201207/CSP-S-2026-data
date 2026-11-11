#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int a[100005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		a[arr[i]]=i;
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
}
