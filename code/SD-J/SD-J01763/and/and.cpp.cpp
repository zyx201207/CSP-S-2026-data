#include<bits/stdc++.h>
using namespace std;
long long n,m,k,zd=-999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>k;
    	if(k>=zd){
    		zd=k;
		}
	}
	cout<<zd;
    return 0;
} 

