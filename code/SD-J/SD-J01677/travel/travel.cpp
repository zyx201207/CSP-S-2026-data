#include<bits/stdc++.h>
using namespace std;
int flag[5];
int main(){
	freopen("travel.in","r",stdin);
  	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		flag[1]=1;
		if(c[0]==d[0] && c[1]==d[1]){
			flag[2]=1;
			int n,m;
			n=c[2]-'A';
			m=d[2]-'A';
			if((n<3 && m<3)||(n>3 && m>3)){
				flag[3]=1;
				if((n-m==1 || m-n==1)&&(c[2]!='C' && d[2]!='D')&&(d[2]!='C' && c[2]!='D')){
					flag[4]=1;
				} 
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<flag[i];
	}
	return 0;
}

