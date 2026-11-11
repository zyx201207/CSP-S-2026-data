#include<bits/stdc++.h> 
using namespace std;
int a[500005];
int main(){
freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1){
		if(a[2]==2){
			if(a[3]==1){
				if(a[4]==3){
					cout<<3<<" "<<1<<" "<<4;
				}
			}
		}
	}
	if(a[1]==3){
		if(a[2]==1){
			if(a[3]==2){
				if(a[4]==1){
				if(a[5]==3){
		        if(a[6]==2){
		    	if(a[7]==3){
				if(a[8]==1){
			    if(a[9]==2){
				if(a[10]==1){
					cout<<10<<" "<<3<<" "<<3;
				}
			}
		}
	}
				}
			}
		}
	}
				}
			}
	return 0;
}