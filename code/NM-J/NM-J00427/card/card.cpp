#include<bits/stdc++.h>
int a[100000];
int k[100000];
using namespace std;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n<=20000 and m<=n)
    {
    	for(int i=0;i<n;i++){
		k=n*m;
    	a[i]=2*k[i]-1;
		}
    	k=n*m;
    	a[i]=2*k[i]-1;
	}
	for(int i=0;i<n;i++){
		cout<<k[i];
	}

    return 0;
}
