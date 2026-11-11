#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool flag1=false,flag2=false,flag3=false,flag4=false;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;flag1=true;
	}else cout<<0;
	
	int cnt=0;
	for(int i=0;i<2;i++){
		if(b[i]==d[i]) cnt++;
	}
	if(cnt==2) flag2=true;
	if(flag2 && flag1) cout<<1;
	else cout<<0;
	
	if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') flag3=true;
	if(b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F') flag3=true;
	if(flag1&&flag2&&flag3){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	if(flag1&&flag3){
		if(b[0]==d[0]){
			if(b[1]==d[1]&& abs(int(b[2]-d[2]))==1){
				flag4=true;
			}else{
				if(b[2]==d[2]&&abs(int(b[1]-d[1]))==1) flag4=true;
			}}}
	
	if(flag4) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
