#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a[200005]={}; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mx = 0;
	for(int i=0;i<n;i++){//ÓÉË­¿ªÊ¼
		int mp = 0;
		for(int j=0;j<m;j++){
			int mpx = 0;
			for(int l=0;l<n;l++){                                                                                                                                                    
				if(a[l]==1){
					mpx = max(mpx,a[i]&a[l]);
				}
			}
			mp = max(mpx,mp);
		}
		mx = max(mp,mx);
	}
	cout<<0;
	return 0;
} 
