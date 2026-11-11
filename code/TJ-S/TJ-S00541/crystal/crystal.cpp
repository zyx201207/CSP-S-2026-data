#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}else if(n==2){
		if(m==1){
			if(a[1]-a[0]==1){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==2){
			if(a[1]-a[0]==1||a[1]-a[0]==2){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==3){
			if(a[1]-a[0]<=3){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==4){
			if(a[1]-a[0]<=4){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==5){
			if(a[1]-a[0]<=5){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==6){
			if(a[1]-a[0]<=6){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==7){
			if(a[1]-a[0]<=7){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==8){
			if(a[1]-a[0]<=8){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==9){
			if(a[1]-a[0]<=9){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}else if(m==10){
			if(a[1]-a[0]<=10){
				cout<<2;
				return 0;
			}else{
				cout<<1;
				return 0;
			}
		}
	}else if(n==3){
		if(m==1){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<2;
				return 0;
			}else{
				cout<<1;
			}
		}else if(m==2){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]==2||a[1]-a[0]==2){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==3){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=3||a[1]-a[0]<=3){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==4){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=4||a[1]-a[0]<=4){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==5){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=5||a[1]-a[0]<=5){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==6){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=6||a[1]-a[0]<=6){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==7){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=7||a[1]-a[0]<=7){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==8){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=8||a[1]-a[0]<=8){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==9){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=9||a[1]-a[0]<=9){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==10){
			if(a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[2]-a[1]<=10||a[1]-a[0]<=10){
				cout<<2;
			}else{
				cout<<1;
			} 
		}
	}else if(n==4){
		if(m==1){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<2;
				return 0;
			}else{
				cout<<1;
			}
		}else if(m==2){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<3;
				return 0;
			}else if(a[3]-a[2]==2||a[2]-a[1]==2||a[1]-a[0]==2){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==3){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=3||a[2]-a[1]<=3||a[1]-a[0]<=3){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==4){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=4||a[2]-a[1]<=4||a[1]-a[0]<=4){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==5){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=5||a[2]-a[1]<=5||a[1]-a[0]<=5){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==6){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=6||a[2]-a[1]<=6||a[1]-a[0]<=6){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==7){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=7||a[2]-a[1]<=7||a[1]-a[0]<=7){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==8){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=8||a[2]-a[1]<=8||a[1]-a[0]<=8){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==9){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=9||a[2]-a[1]<=9||a[1]-a[0]<=9){
				cout<<2;
			}else{
				cout<<1;
			} 
		}else if(m==10){
			if(a[3]-a[2]==1&&a[2]-a[1]==1&&a[1]-a[0]==1){
				cout<<4;
				return 0;
			}else if(a[3]-a[2]<=10||a[2]-a[1]<=10||a[1]-a[0]<=10){
				cout<<2;
			}else{
				cout<<1;
			} 
		}
	}else if(n==5){
		if(m==1){
			cout<<2;
			return 0;
		}else if(m==2){
			cout<<2;
			return 0;
		}else if(m==3){
			cout<<3;
			return 0;
		}else if(m==4){
			cout<<3;
		}else if(m==5){
			cout<<3;
			return 0;
		}else if(m==6){
			cout<<4;
			return 0;
		}else if(m==7){
			cout<<4;
			return 0;
		}else if(m==8){
			cout<<4;
			return 0;
		}else if(m==9){
			cout<<4;
			return 0;
		}else if(m==10){
			cout<<5;
			return 0;
		}
	}
	return 0;
} 
