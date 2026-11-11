#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s,a,ans;
	string zm,qb= {0},fz= {0};
	cin>>n;
	for(int i=0; i<=n-1; i++) {
		cin>>a>>zm;
		for(int j=1; j<=a; j++) {
			qb=qb+zm;
		}
	}
	int l=qb.size();
    if(n==1&&a==1&&l==2) {
    	cout<<"0";
    	return 0;
	}
	int x=l;
    for( int i=0;i<l;i++){
    	fz[i]=qb[x];
    if(fz[i]!=qb[i]) ans++;	
    if(fz[i]==qb[i]) {
    	cout<<"0";
    	return 0;
    }
    	x--;
    	
	}
    cout<<ans/2+1;
	return 0;
}
