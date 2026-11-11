#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
const int A=3e5+5;
int arr[N];
int Max=-1e9;
int vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	cout<<arr[n]<<endl;
	return 0;
} 
