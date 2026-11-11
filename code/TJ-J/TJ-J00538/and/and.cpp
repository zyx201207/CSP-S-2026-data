#include<bits/stdc++.h>
using namespace std;

long long q,v,n,m,ans,u;
long long a[200005],maxs[200005];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(long long i=0;i<m;i++){
        for(int j=0;j<n;j++){
        	if(a[j]>u){
        		u=a[j];
        		q=j;
			}
       	}
       	maxs[v]=u;
		a[q]=-1e5;
    	u=0,v++;
	}
	
    ans=maxs[0];
    for(long long i=1;i<v;i++){
		ans&=maxs[i];
	}

	cout<<ans;
	return 0;
}
