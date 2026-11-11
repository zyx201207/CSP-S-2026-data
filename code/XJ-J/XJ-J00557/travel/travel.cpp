#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("text","travel.in","r")
	freopen("text","travel.out","w")
	cin>>c1>>c2>>s1>>s2;
	int c1,c2,s1,s2;
	for(int i;i<0;){
		if(c1>=c2||c1<=c2||s1>=c2&&s1>=s2||s1==c2||s2==c1){
			cout<<'1';
			else{
				cout<<'0';
			} 
		}
	}
	
	return 0;
}
