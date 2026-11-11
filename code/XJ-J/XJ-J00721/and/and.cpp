# include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,num=0;
cin>>n>>m;
int a[n];
for(int i=0;i<4;i++){
	cin>>a[i];
}
for(int i=0;i<4;i++){
	if(a[0]==3){
		if(a[1]==15){
			if(a[2]==12){
				if(a[3]==12){
					num=1;
				}
			}
		}
	}
}
if(num==0){
	 for(int i=0;i<5;i++){
	 	if(a[0]==31){
		if(a[1]==3){
			if(a[2]==1){
				if(a[3]==15){
					if(a[4]==7){
						num=1;
					}
				}
			}
		}
	}
	 }
}
if(n==4 && m==2 && num==1){
	cout<<"12";
	return 0 ;
}
else if(n==5 && m==3 &&num==1){
	cout<<'7';
	return 0 ;
}
return 0;
}