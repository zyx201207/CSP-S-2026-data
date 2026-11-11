#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			printf("0000");
			return 0;
		}
	}
	printf("1");
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			printf("000");
			return 0;
		}
	}
	printf("1");
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
} 
