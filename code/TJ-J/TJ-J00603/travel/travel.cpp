#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[4]={0};
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
		string h1="",h2="";
		h1+=s1[0];
		h1+=s1[1];
		h2+=s2[0];
		h2+=s2[1];
		if(h1==h2){
			ans[1]=1;
			if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
				ans[2]=1;
				if(s1[2]=='B' || s2[2]=='B'){
					ans[3]=1;
				}
			}
			else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s1[2]<='F'){
				ans[2]=1;
				ans[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
