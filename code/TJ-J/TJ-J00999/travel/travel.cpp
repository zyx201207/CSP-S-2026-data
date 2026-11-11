#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	int cnt=0;
	for(int i=0;i<4;i++){
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2){
		cnt=1;	
		}else if(s1+1==s2){
		cnt=1;
		}else{
		cnt=0;
	}
}
	cout<<cnt<<cnt<<cnt<<cnt;
	return 0;
}
