#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1;
	string x2,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		cout<<"1";
		if(x2[0]==y2[0]&&x2[1]==y2[1]){
			cout<<"1";
			if(x2[3]="A"||x2[3]="B"||x2[3]="C"&&y2[3]="A"||y2[3]="B"||y2[3]="C"||x2[3]="D"||x2[3]="F"&&y2[3]="D"||y2[3]="F"){
				cout<<"1";
				if(x2[2]+1==y2[2]||y2[2]+1==x2[2]){
					cout<<"1";
				}
				else{
				cout<<"0";
				}
			}
			else{
			cout<<"0";
			}
}
	else{
	cout<<"0";
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}