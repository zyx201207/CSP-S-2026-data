#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2;
int sum=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		sum=sum+1000;
	}else{
		cout<<"0000";
		return 0;
	}
	char a=s1,b=s2;
	if(a/10==b/10){
		sum+=100;
	}else{
		cout<<"1000";
		return 0;
	}
	if(a%10==b%10+1&&a!=67&&b!=68||a%10==b%10-1&&a!=67&&b!=68||a%10==b%10+1&&a!=68&&b!=67||a%10==b%10-1&&a!=68&&b!=67){
		sum+=10;
	}else if(a%10==b%10+1&&a==67&&b==68||a%10==b%10-1&&a==67&&b==68||a%10==b%10+1&&a==68&&b==67||a%10==b%10-1&&a==68&&b==67){
		sum+=1;
	}else if(a%10==b%10+1&&a==67&&b==68||a%10==b%10-1&&a==67&&b==68||a%10==b%10+1&&a==68&&b==67||a%10==b%10-1&&a==68&&b==67){
		cout<<"1100";
		return 0;
	}
	cout<<sum;
	return 0;
}
//travel
//1=49,a=97