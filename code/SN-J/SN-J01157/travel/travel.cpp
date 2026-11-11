#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char a[2],b[3],c[2],d[3];
	for(int i=0;i<=2-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<=3-1;i++){
		cin>>b[i];
	}
	for(int i=0;i<=2-1;i++){
		cin>>c[i];
	}
	for(int i=0;i<=3-1;i++){
		cin>>d[i];
	}
	if(a[0]==c[0]&&a[1]==a[1]){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	if(a[0]==c[0]&&a[1]==a[1]&&b[1]==d[1]){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	if(a[0]==c[0]&&a[1]==a[1]&&b[1]==d[1]&&b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";}
	if(a[0]==c[0]&&a[1]==a[1]&&b[1]==d[1]&&b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'&&b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
