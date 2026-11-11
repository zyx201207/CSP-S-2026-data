#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int sum1=0,sum2=0,sum3=0,sum4=0;
	if(c1==c2){
		sum1=1;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		sum2=1;
	}if(sum2==1&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		sum3=1;
	}if(sum3==1&&(s1[2]==char(int(s2[2])+1)||s1[2]==char(int(s2[2])-1))){
		sum4=1;
	}cout<<sum1<<sum2<<sum3<<sum4;
	return 0;
}