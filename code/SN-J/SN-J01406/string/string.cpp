#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n,x,ii=1,jj=0,cnt;
char y;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int o=1;o<=n;o++){
		cin>>x>>y;
		for(int kk=1;kk<=x;kk++){
			s[ii]=y;
			ii++;
		}
	}
	if(ii%2==0){
	for(int i=1;i<=(ii/2);i++){
		if(s[i]!=s[ii-i]){
			cnt++;
		}
	}
    }else{
   	for(int i=1;i<=(ii/2)+1;i++){
		if(s[i]!=s[ii-i]){
			cnt++;
		}
	}
	}
	cout<<cnt;
	/*for(int j=1;j<=ii;j++){
		cout<<s[j];
	}*/
	return 0;
}
