#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int sum=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		sum=1;
	}
	else cout<<0;
	if(sum==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{ cout<<0;
		sum=0;
	}
	if(((int(s1[2])<=67&&int(s2[2])<=67)||(int(s1[2])>67&&int(s2[2])>67))&&sum==1){
		cout<<1;
	}
	else{
		 cout<<0;
		 sum=0;
	 }
	if((((int(s1[2])<=67&&int(s2[2])<=67)||(int(s1[2])>67&&int(s2[2])>67))&&(int(s1[2])==int(s2[2])+1||int(s1[2])==int(s2[2])-1))&&sum==1)cout<<1;
	else cout<<0;
	return 0;
}
