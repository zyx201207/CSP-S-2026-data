#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	string c1[n+1],d;
	int a1[n+1];
	bool s=true;
	for(int i=0;i<n;i++){
	cin>>a1[i]>>c1[i];	
	}
	for(int i=0;i<n;i++){
		if(c1[i]!=c1[i+1]){
		s=false;
		break;}
	}
	if(s==true){
	cout<<0;}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
