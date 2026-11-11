#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,b[500005],t,m,ans[500005],d[500005],c[500005],a[500005],ttt=(1<<30)-1;
vector<int>v,vv;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	
	
} 
