#include<bits/stdc++.h>
using namespace std;
int a,c;
char b[4],d[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for (int i=1;i<=3;i++){
		cin>>b[i];
	}
	cin>>c;
	int f=0,fl=0;
	for (int i=1;i<=3;i++){
		cin>>d[i];
	}
	if (b[3]=='D'||b[3]=='F'){
		f=1;
	}
	if (d[3]=='D'||d[3]=='F'){
		fl=1;
	}
	if (a!=c){
		cout<<"0000";
		return 0;
	}
	if (b[1]!=d[1]||b[2]!=d[2]){
		cout<<"1000";
		return 0;
	}
	if (f!=fl){
		cout<<"1100";
		return 0;
	}
	if (int(b[3])-int(d[3])!=1&&int(b[3])-int(d[3])!=-1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
