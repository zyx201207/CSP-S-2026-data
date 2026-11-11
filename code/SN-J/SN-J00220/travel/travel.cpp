#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b) {
		cout<<"1";
		int l=1;
	}
	else{
		cout<<"0";
		int l=0;
	}
	int f[3],j[3];
	
	for(int i=0;i<=2;i++) {
		if(c[i]<="Z"&&c[i]>="A")
		f[i]=c[i]-"A";
		else
		f[i]=c[i];
	}
	for(int i=0;i<=2;i++) {
		if(d[i]<="Z"&&d[i]>="A")
		j[i]=d[i]-"A";
		else
		j[i]=d[i];
	}
	if((((f[2]==0)||(f[2]==1)||(f[2]==3))&&((j[2]==0)||(j[2]==1)||(j[2]==3)))||(((f[2]==3)||(f[2]==4))&&((j[2]==3)||(j[2]==4)) )){
		int jf=1;
	}else{
		int jf=0;
	}
	if(l==1&&f[0]==j[0]&&f[1]==j[1]&&jf==1){
		cout<<"1";
		int l=1;
	}
	else{
		cout<<"0";
		int l=0;
	}
	if(((f[2]+1==j[2])||(j[2]+1==f[2]))&&(l==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
