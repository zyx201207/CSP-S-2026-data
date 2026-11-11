#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int ans[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int p,q;
	p=b[0]-'0',q=b[1]-'0';
	int a1=p*10+q;
	int r,s;
	r=d[0]-'0',s=d[1]-'0';
	int a2=r*10+s;//ÅÅÊı 
	//cout<<a1<<" "<<a2;
	int a3=b[2]-'A'+1,a4=d[2]-'A'+1;//×ùÎ» 
	//cout<<a3<<" "<<a4;
	if(a==c){
		ans[1]=1;
	}else{
		ans[1]=0;
	}
	if(a1==a2&&a==c){
		ans[2]=1;
	}else{
		ans[2]=0;
	}
	if(a1==a2&&a==c){
		if((a3==1&&a4==2)||(a3==1&&a4==3)||(a3==2&&a4==3)||(a3==2&&a4==1)||(a3==3&&a4==1)||(a3==3&&a4==2)){
			ans[3]=1;
		}else{
			ans[3]=0;
		}
	}
	if((a1==a2&&a==c)&&((a3==1&&a4==2)||(a3==2&&a4==3)||(a3==4&&a4==6)||(a3==2&&a4==1)||(a3==3&&a4==2)||(a3==6&&a4==4))){
		ans[4]=1;
	}else{
		ans[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
} 
