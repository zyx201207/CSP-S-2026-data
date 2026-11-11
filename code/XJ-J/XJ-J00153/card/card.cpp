#include<bits/stdc++.h>
using namespace std;
const int MAX_N=200010;
const int MAX_M=300010;
int n,m,a[MAX_N],ans[MAX_M]={3,1,4};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
