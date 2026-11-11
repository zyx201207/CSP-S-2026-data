//刘立恒交大附中 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,c=0;
	char n[8],m[8];
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>n[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>m[i];
	}
	
	if(a==b){
		cout<<1;
			if(n[1]==m[1] && n[2]==m[2]){
			cout<<1;
		}else{
			cout<<0;
		}
		if((n[3]>='C' && m[3]>='C') || (n[3]<='D' && m[3]<='D')){
			cout<<1;
		}else{
			cout<<0;
		}
		if(n[3]-m[3]==-1 || n[3]-m[3]==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
