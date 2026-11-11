#include<bits/stdc++.h>
using namespace std;
signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int a[100000],c[100000];
	int n,m,max=0;

	cin>>n>>m;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0){
			for(int z=0;z<i;z++){	
				int y=m;
				b[i]=0;	
				for(int x=z;x<i;x++){
				
					if(a[i]-a[x]<=y){
						b[i]=b[i]+1;
						y=y+a[x]-a[i];
					}
					if(b[i]>c[i]){
						c[i]=b[i];
					}
				
			}	
		}
	}
}
	sort(c,c+n);
	int top=c[n-1]+1;
	cout<<top;
	return 0;
}

