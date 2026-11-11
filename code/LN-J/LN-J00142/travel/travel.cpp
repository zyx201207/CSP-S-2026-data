#include<bits/stdc++.h>
using namespace std;
bool i,j,k,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		i=1;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			j=1;
			if((a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||(a1[2]>='D'&&a1[2]<='E'&&b1[2]>='D'&&b1[2]<='E')){
				k=1;
				if(abs(a1[2]-b1[2])==1){
					l=1;
				}
		    }
		}
	}
	cout<<i<<j<<k<<l;
    return 0;
}
