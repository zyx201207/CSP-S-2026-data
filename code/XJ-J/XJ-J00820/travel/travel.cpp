#include<bits/stdc++.h>
using namespace std;
string x,y,pa,pb;
bool flag[5];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>pa>>x>>pb>>y;
	if(pa==pb){
		flag[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		flag[2]=1;
		int a=x[2]-'A';
	    int b=y[2]-'A';
	    if(a>=3&&b<3){
	      flag[3]=0;
	      for(int i=1;i<=4;i++){
	  	    cout<<flag[i];
	      }
	      return 0;
	   }else if(b>=3&&a<3){
	      flag[3]=0;
	      for(int i=1;i<=4;i++){
	  	    cout<<flag[i];
	      }
	      return 0;
	   }else{
	      flag[3]=1;
	   }
	   if(abs(a-b)==1){
	     flag[4]=1;
	   }
	}
	for(int i=1;i<=4;i++){
	   cout<<flag[i];
	}
	return 0;
}

