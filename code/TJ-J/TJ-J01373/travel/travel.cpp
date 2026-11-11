#include<bits/stdc++.h>
using namespace std;

int mian(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool x,m;
	char y[5],n[5];
	cin>>x>>y>>m>>n;
	if(x=m){
        cout<<1;
        if(y[1]=n[1]){
            cout<<1;
			if(y[2]=n[2]+1){
				cout<<11;
			}
			else cout<<00;
		}
		else cout<<000;
		
	
	}
	else cout<<0000;
	return 0;
}
