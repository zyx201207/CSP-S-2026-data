#include<bits/stdc++.h>
using namespace std;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+1+n,greater<int>());
    int maxx=a[1];
    for(int i=2;i<=m;i++){
    	maxx=maxx&a[i];
	}
	cout<<maxx;
	
	return 0;
} 
