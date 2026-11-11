#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("travel.in","r",stdin);
	int b[4]={};
	char a[10]={};
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	cout<<endl;
	int cnt=1;
    for(int i=1;i<=4;i+=2){
    	if(a[i]==a[i+5] && a[i+1]==a[i+6]) b[cnt]=1;
    	cnt++;
	}
	if(b[1]==0 || b[2]==0){
		b[3]=0;
		b[4]=0;
		for(int i=1;i<=4;i++){
			cout<<b[i]; 
		}
		return 0;
	}
	if(a[5]<68 && a[10]<68 || a[5]>=68 && a[10]>=68){
		b[3]=1;
	}else{
		b[3]=0;
		b[4]=0;
		for(int i=1;i<=4;i++){
			cout<<b[i]; 
		}
		return 0;
	}
	if(a[5]==a[10]+1 || a[5]==a[10]-1){
		b[4]=1;
	}else b[4]=0;
	for(int i=1;i<=4;i++){
			cout<<b[i]; 
		}
//	freopen("travel.out","w",stdout);
}
