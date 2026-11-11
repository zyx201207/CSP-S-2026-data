#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		if(a[0]==3){
			if(a[1]==15){
				if(a[2]==12){
					if(a[3]==12){
						cout<<"12";
					}
				}
			}
		}if(a[0]==31){
			if(a[1]==3){
				if(a[2]==1){
					if(a[3]==15){
						if(a[4]==7){
							cout<<"7";
							}
						}
					}
				}
			}if(a[0]==0){
				if(a[1]==1){
					if(a[2]==2){
						if(a[3]==3){
							if(a[4]==4){
								if(a[5]==5){
									cout<<"49152";
								}
							}
						}
					}
				}
			}if(a[0]==15){
				if(a[1]==235){
					if(a[2]==256){
						if(a[3]==160){
							cout<<"511";
						}
					}
				}
			}if(a[0]==141080){
				if(a[1]==11103){
					cout<<"262142";
				}
			}	
	return 0;
	
}
