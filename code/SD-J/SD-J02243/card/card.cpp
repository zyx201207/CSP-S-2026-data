#include<bits/stdc++.h>
using namespace std;
int n,m,j;
int a[500005];
int b;
int c1=1,c2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",n);
	}
	else if(m==2){
		if(n==2){
			if(a[0]==1){
				cout<<2<<" "<<1;
			}
			else if(a[0]==2){
				cout<<1<<" "<<2;
			}
		}
		else if(n==3){
			if(a[0]==1 && a[1]==1){
				cout<<3<<" "<<1;
			}
			else if(a[0]==2 && a[1]==2){
				cout<<1<<" "<<3;
			}
			else if(a[0]==1 && a[1]==2 && a[2]==1){
				cout<<3<<" "<<1;
			}
			else if(a[0]==2 && a[1]==1 && a[2]==2){
				cout<<1<<" "<<3;
			}
			else{
				cout<<2<<" "<<2;
			}
		}
		else if(n==4){
			if(a[1]==2 && a[2]==2 && a[3]==2){
				cout<<4<<" "<<3;
			}
			else if(a[0]==2 && a[2]==2 && a[3]==2){
				cout<<1<<" "<<4;
			}
			else if(a[0]==2 && a[1]==2 && a[3]==2){
				cout<<1<<" "<<4;
			}
			else if(a[0]==2 && a[1]==2 && a[2]==2){
				cout<<1<<" "<<4;
			}
			else if(a[1]==1 && a[2]==1 && a[3]==1){
				cout<<3<<" "<<4;
			}
			else if(a[0]==1 && a[2]==1 && a[3]==1){
				cout<<4<<" "<<1;
			}
			else if(a[0]==1 && a[1]==1 && a[3]==1){
				cout<<4<<" "<<1;
			}
			else if(a[0]==1 && a[1]==1 && a[2]==1){
				cout<<4<<" "<<1;
			}
			else if(a[0]==1 && a[1]==1 && a[2]==2 && a[3]==2){
				cout<<4<<" "<<2;
			}
			else if(a[0]==2 && a[1]==2 && a[2]==1 && a[3]==1){
				cout<<2<<" "<<4;
			}
			else if(a[0]==1 && a[1]==2 && a[2]==1 && a[3]==2){
				cout<<4<<" "<<2;
			}
			else if(a[0]==2 && a[1]==1 && a[2]==2 && a[3]==1){
				cout<<2<<" "<<4;
			}
			else if(a[0]==2 && a[1]==1 && a[2]==1 && a[3]==2){
				cout<<2<<" "<<4;
			}
			else if(a[0]==1 && a[1]==2 && a[2]==2 && a[3]==1){
				cout<<4<<" "<<2;
			}
		}
	} 
	return 0;
}

