#include<bits/stdc++.h>
#define int long long
using namespace std;
char ans[5]={'0','0','0','0','0'};
string aa,ab,ba,bb;
signed main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>aa>>ab>>ba>>bb;
  if(aa==ba){
  	ans[1]='1';
  	if(ab[0]==bb[0]&&ab[1]==bb[1]){
  		ans[2]='1';
  		int a=ab[2]-'A';
  		int b=bb[2]-'A';
  		if((a<=2&&b<=2)||(a>2&&b>2)){
  			ans[3]='1';
  			if(a-b==1||b-a==1){
  				ans[4]='1';
			  }
		  }
	}
  }
  for(int i=1;i<=4;i++){
  	cout<<ans[i];
  }
  return 0;
}
