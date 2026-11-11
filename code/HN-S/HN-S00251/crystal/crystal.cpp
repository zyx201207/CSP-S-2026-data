#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	cin>>a>>b;
	long long c[a];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c+0,c+a);
	int zd=1,bj;
	for(int i=1;i<a;i++){
		long long h=b;
		bj=1;
		for(int p=i-1;p>=0;p--){
			if(h>=c[i]-c[p]){
				bj++;
				h-=(c[i]-c[p]);
			}
		}
		zd=max(zd,bj);
	}
	cout<<zd;
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
