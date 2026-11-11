#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,tmax=1,teshua=1;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	
	sort(a,a+n);
	
	for(int i=1;i<=n;i++){
		if(a[i-1]!=i){
			teshua=0;
			break;
		}
	}
	
	if(teshua){
		int jj=1;
		while(m>=0){
			m-=jj;
			jj++;
			if(m>=0) tmax++;
		}
		cout<<tmax;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		int p=m;
		int t=1;
		for(int j=i-1;j>=0;j--){
			if(p>=0){
				p-=a[i]-a[j];
				if(p>=0){
					t++;
				}
			}
			else{
				break;
			}
		if(t>tmax) tmax=t;
		}
	}
	cout<<tmax;

	return 0;
} 
