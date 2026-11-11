#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N],ans[M],b[M]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		b[a[i]]=max(a[i],b[a[i]]);
	} 
	for(int i=0;i<m;i++){
		cout<<b[i]+1<<" ";
	}
	return 0;
}
