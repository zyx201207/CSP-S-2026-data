#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[5];
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}int q=1;
	for(int i=0;i<=1;i++){
		if(a[1][i]!=a[3][i]){
			q=0;
		}
	}
	if(q==0){
		cout<<"0000";
		return 0;
	}
	cout<<q;
	for(int i=0;i<=1;i++){
		if(a[2][i]!=a[4][i]){
			q=0;
		}
	}
	if(q==0){
		cout<<"000";
		return 0;
	}cout<<q;
	int s;
	q=0;
	if(a[2][2]<='C'&&a[4][2]<='C'){
		q=1;
		s=1;
	}
	if(a[2][2]>='D'&&a[4][2]>='D'){
		q=1;
		s=2;
	}
	if(q==0){
		cout<<"00";
		return 0;
	}cout<<q;
	if(s==2){
		cout<<1;
		return 0;
	}
	if(s==1){
		int e=a[2][2]-a[4][2];
		if(e>-2 &&e<=1){
			cout<<1;
			return 0;
		}
	}cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
