#include<bits/stdc++.h>
using namespace std;
int s[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		s[1]=1;
		if(x[0]==y[0]&&x[1]==y[1]){
			s[2]=1;
			int n=x[2]-'A',m=y[2]-'A';
			int q=0,p=0;
			if(n>=0&&n<=2&&m>=0&&m<=2&&n!=m){
				s[3]=1;
				q=1;
			}else if(n+m==8&&n!=m&&n<=5&&m<=5){
				s[3]=1;
				p=1;
			}
			if((abs(n-m)==1&&s[3]==1&&q==1)||(p=1&&s[3]==1)){
				s[4]=1;
			}			
		}
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
} 
