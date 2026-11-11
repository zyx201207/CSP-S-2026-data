#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[3],b[3],a1[10],b1[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a[i+1]=c1[i]-'0';
		b[i+1]=c2[i]-'0';
		a1[i+1]=s1[i]-'0';
		b1[i+1]=s2[i]-'0';
	}
	a1[3]=s1[2]-'A';
	b1[3]=s2[2]-'A';
	for(int i=1;i<=2;i++){
		if(a[i]!=b[i]){
			cout<<"0000";
			break;
		}
		else if(i==2){
			cout<<'1';
			for(int j=1;j<=2;j++){
				if(a1[j]!=b1[j]){
				cout<<"000";
				break;
				}
					else if(j==2){
					cout<<'1';
					if((a1[3]<=2&&b1[3]<=2)||(a1[3]>2&&b1[3]>2)){
						cout<<'1';
						if(a1[3]-b1[3]==1||b1[3]-a1[3]==1){
							cout<<'1';
						}
						else{
							cout<<'0';
						}
					}
							else{
								cout<<"00";
						}
					}
			}
		}
	}
	
	return 0;
}
