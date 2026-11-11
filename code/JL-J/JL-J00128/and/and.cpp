#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],b[20005],maxn=-0x3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    while(a[i]>0){
		    b[i]=a[i]%2;
		    a[i]/=2;	
		}
	}
	while(m--){
	    for(int i=1;i<=n;i++){
            maxn=max(maxn,b[i]&b[i+1]);	    	
		}
	}
	cout<<maxn;
	
    return 0;	
}
