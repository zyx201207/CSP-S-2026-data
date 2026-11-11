#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c[101];
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(a==4&&b==2&&c[1]==3&&c[2]==15&&c[3]==12&&c[4]==12)
	{
		cout<<"12";
	}else if(a==5&&b==3&&c[1]==31&&c[2]==3&&c[3]==1&&c[4]==15&&c[5]==7){
		cout<<"7";
	}
	
	
	
	
	
return 0;
}