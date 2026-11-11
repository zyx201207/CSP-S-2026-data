#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string m1,m2,n1,n2;
	cin >> m1 >> m2 >> n1 >> n2;
	bool flag1=true,flag2=true,flag3=true,flag4=true;
	if(m1!=n1) flag1=false;
	else if(!(m2[0]==n2[0] && m2[1]==n2[1])){
		flag2=false;
	}
	else if(!( (m2[2]<='C' && n2[2]<='C') || (m2[2]>'C' && n2[2]>'C') )){
		flag3=false;
	}
	else if(!(int(m2[2]-n2[2])==1 || int(m2[2]-n2[2])==-1 )) 
	{
		flag4=false;
	}
	if(!flag1) cout << "0000";
	else if(!flag2) cout << "1000";
	else if(!flag3) cout << "1100";
	else if(!flag4) cout << "1110";
	else cout << "1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
