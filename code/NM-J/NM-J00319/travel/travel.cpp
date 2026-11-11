#include<bits/stdc++.h>
using namespace std;
long long n[100086],m[100086],ans[10086];
string q[100086];
char w[10086];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
    	cin>>n[i]>>m[i]>>w[i];
	}
	if(n[1]==n[2]){
		ans[1]=1;
		if(m[1]==m[2]){
			ans[2]=1;
			if((w[1]=='A'&&w[2]=='C')||(w[2]=='A'&&w[1]=='C')||((w[1]!='C'&&w[1]!='D'&&w[2]!='C'&&w[2]!='D')&&(w[1]==w[2]+1||w[1]==w[2]-1))){
				ans[3]=1;
				if(w[1]==w[2]+1||w[1]==w[2]-1){
					ans[4]=1;
				}
			}
		}
	} 
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
    return 0;
}
