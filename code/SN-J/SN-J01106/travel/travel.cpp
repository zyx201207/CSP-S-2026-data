#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool a,a1,a2,a3;
	int n=(c1[0]-'0')*10+(c1[1]-'0');
	int m=(c2[0]-'0')*10+(c2[1]-'0');
	int x=(s1[0]-'0')*10+(s1[1]-'0');
	int y=(s2[0]-'0')*10+(s2[1]-'0');
	cin>>c1>>s1>>c2>>s2;
	int q=s1[2]-'A'+1;
	int b=s2[2]-'A'+1;
	if(n==m){
		a=1;
	}
	if(a&&x==y){
		a1=1;
	}
	if(a1&&((q<=3&&b<3)||(q>3&&b>3))){
		a2=1;
	}
	if(a2&&q+1==b||b+1==q){
		a3=1;
	}
	cout<<a<<a1<<a2<<a3;
	return 0;
}
