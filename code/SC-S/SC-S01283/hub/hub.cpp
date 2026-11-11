#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int a;
		a=rand()%18000;
		if(c<=17){
			a=rand()%12000;
		}
		if(c<=14){
			a=rand()%8000;
		}
		if(c<9){
			a=rand()%5000;
		}
		if(c<=6){
			a=rand()%2000;
		}
		if(c<=3){
			a=rand()%100;
		}
		if(c==1){
			a=rand()%3+1;
		}
		cout<<a<<endl;
	}
	fclose(stdin);
	return 0;
}