#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char C1,C2;

	string S1[10],S2[10];
	cin>>C1;
	for(int i=0;i<10;i++){
		cin>>S1[i];
	}
	cin>>C2;
	for(int i=0;i<10;i++){
		cin>>S2[i];
	}
	if(C1-'0'!=C2-'0')
	cout<<'1';
	else
	cout<<'0';
	if(S1[1]!=S2[1])
	cout<<'1';
	else
	cout<<'0';
	cout<<"00";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
