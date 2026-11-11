#include<bits/stdc++.h>
#define int long long 
using namespace std;
string a,b,c,d;
char b1[10];
char d1[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=1;i<=3;i++){
		b1[i]=b[i-1];
		d1[i]=d[i-1];
	}
	if(a==c){
		cout<<1;
		if(b1[1]==d1[1]&&b1[2]==d1[2]){
			cout<<1;
			if(b1[3]<='C'&&d1[3]<='C' || b1[3]>='D'&&d1[3]>='D'){
			    cout<<1;
			    if(b1[3]+1==d1[3]||d1[3]+1==b1[3]){
			   	    cout<<1;
			   	   	return 0;
			    }
			    else{
			    	cout<<0;
			    	return 0;
				}
			    
			   
			}  
			else{
				cout<<0<<0;
			    return 0;
			}
		}
		else
		    cout<<0<<0<<0;
		   	return 0;
	}
	else{
	    cout<<0<<0<<0<<0;
	    return 0;
	}    
	return 0;
} 
