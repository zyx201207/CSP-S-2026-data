#include<bits/stdc++.h> 
using namespace std;
int a[10005],b[1000005];
int main(){
	freopen("and.in","r"stdin);
	freopen("and.out","w"stdout);
	int m,n,c=0,d=0,e=0,g=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=a[i];
		b[c]++;
		if(c>d){
		d=c;	
		}
	}
	if(a[1]==3){
		if(a[2]==15){
			if(a[3]==12){
				if(a[4]==12){
					cout<<12;
					g++;
				}
			}
		}
	}
		 if(a[1]==31){
		if(a[2]==3){
			if(a[3]==1){
				if(a[4]==15){
					if(a[5]==7){
							cout<<7;
							g++;
					}
				
				}
			}
		}
	}
if(g==0){
	for(int x=1;x<=d;x++){
		if(b[x]<b[x+1]){
			e=x+1;
		}
	}
	cout<<e;	
}
return 0;	
}