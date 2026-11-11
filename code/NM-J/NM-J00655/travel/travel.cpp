#include<bits/stdc++.h>
using namespace std;
char a[2],a1[3],b[2],b1[3];
bool x1=true,x2=true,x3=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>a1[1]>>a1[2]>>a1[3];
	cin>>b[1]>>b[2]>>b1[1]>>b1[2]>>b1[3];
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}else{
		cout<<0;
		x1=false;
	}
	if(a1[1]==b1[1]&&a1[2]==b1[2]&&x1==true){
		cout<<1;
	}else{
		cout<<0;
		x2=false;
	}
	if(((int(a1[3])<=67&&int(b1[3])<=67)||(int(a1[3])>67&&int(b1[3])>67))&&x2==true){
		cout<<1;
	}else{
		cout<<0;
		x3=false;
	}
	if(((int(a1[3])-int(b1[3])==1)||(int(a1[3])-int(b1[3])==-1)||(int(a1[3])>67&&int(b1[3])>67))&&x3==true){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
