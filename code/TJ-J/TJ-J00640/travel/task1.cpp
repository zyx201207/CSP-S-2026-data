#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char x1,x2,r1,r2;
	cin>>x1>>x2>>r1>>r2;
	int x=x2-'0',r=r2-'0';
	if(x1==r1){
		cout<<'1'<<" ";
		if(x/100==r/100){
			cout<<'1'<<" ";
			if(x%10+1==r%10 || x%10-1==r%10){
				cout<<'1'<<" "<<'1';
			}else{
				if(x%10+2==r%10 || x%10-2==r%10){
					cout<<'1'<<" "<<'0';
				}else{
					cout<<'0'<<" "<<'0';
				}
			}
		}else{
			cout<<'0'<<" "<<'0'<<" "<<'0';
		}
	} else{
		cout<<'0'<<" "<<'0'<<" "<<'0'<<" "<<'0';
	}
	


	return 0;
}
