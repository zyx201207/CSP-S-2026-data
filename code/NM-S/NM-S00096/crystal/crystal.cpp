#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],sub[N];
void add(int a,int l,int r){
	sub[l]-=a,sub[r+1]+=a;
}
int main(){
	// freopen("crystal.in","r",stdin);
	// freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i],add(a[i],i,i);
	}
	for(int i=0;i<n;i++)cout<<sub[i]<<" ";
	
	return 0;
}
