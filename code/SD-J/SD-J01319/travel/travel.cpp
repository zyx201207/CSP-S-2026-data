#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		ans=0;
	}
	cout<<ans;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		ans=0;
	}cout<<ans;
	if(s1[2]<'D'){
		if(s2[2]>='D'){
			ans=0;
		}
	}else{
		if(s2[2]<'D'){
			ans=0;
		}
	}cout<<ans;
	if(ans==1){
		if(s1[2]=='A'&&s2[2]=='C'){
		    ans=0;
		}else if(s1[2]=='C'&&s2[2]=='A'){
		   	ans=0;
		}		
	}cout<<ans;
	return 0;
}
