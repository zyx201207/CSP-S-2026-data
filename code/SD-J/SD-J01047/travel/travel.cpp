#include<bits/stdc++.h>
using namespace std;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		ans[0]=1;
		if(a2.substr(0,2)==a4.substr(0,2)){
			ans[1]++;
			if((a2[2]>='D'&&a2[2]<='F'&&a4[2]>='D'&&a4[2]<='F')||(a2[2]>='A'&&a2[2]<='C'&&a4[2]>='A'&&a4[2]<='C')){
				ans[2]++;
				if(a2[2]-a4[2]==1||a4[2]-a2[2]==1)ans[3]++;
			}
	
	}
	
	}
	
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
