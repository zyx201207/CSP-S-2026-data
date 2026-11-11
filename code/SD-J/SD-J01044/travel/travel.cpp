#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	char a[3],b[3],c[3],d[3];
	cin >> a[0] >> a[1]>> b[0] >> b[1]>> b[2] >> c[0]>> c[1] >> d[0]>> d[1] >> d[2];
	if(b[2]=='F'){
		b[2]='E';
	}
	if(d[2]=='F'){
		d[2]='E';
	}
	if(a[1]!=c[1]){
		cout << "0000";
	}else if(b[1]!=d[1]){
		cout << "1000";
	}else if((b[2]=='A' || b[2]=='B') && (d[2]=='C' || d[2]=='D' || d[2]=='E') || (d[2]=='A' || d[2]=='B') && (b[2]=='C' || b[2]=='D' || b[2]=='E')){
		cout << "1100";
	}else if(int(b[2])-int(d[2])!=1 && int(d[2])-int(b[2])!=1 ){
		cout << "1110";
	}else{
		cout << "1111";
	}
	
	//fclose(stdin);
	//fclose(stdout); 
	
	return 0;
}
