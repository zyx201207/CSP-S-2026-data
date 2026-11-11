#include<bits/stdc++.h>
using namespace std;
int main(){
	freoen("travel.in","r",stdin);
	freoen("trevel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
			cout<<"1";
		}else{
			cout<<"0000";
			return 0;
		}
	for(int i=0;i<3;i++){
		if(c2[i]==c4[i]||c2[i]+1==c4[i]||c2[i]-1==c4[i]||c2[i]==c4[i]+1||c2[i]==c4[i]-1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}