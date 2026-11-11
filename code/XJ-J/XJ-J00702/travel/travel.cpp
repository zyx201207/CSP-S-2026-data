#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(c1[0] == c2[0] && c1[1] == c2[1] && c1[0] != '0'){
		if(c1[1] != '6' ){
			ans1 = 1;
			ans2 = 1;
		}
	}
	else if(c1[0] == c2[0] && c1[1] == c2[1] && c1[1] != '1'){
		ans1 = 1;
		ans2 = 1;
	}
	//zuowei
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		ans3 = 1;
	}
	
	if(abs(a-b) == 1){
		if(a == 'C'){
			if(b == 'D')
				ans4 = 0;
		}
		else if(a == 'D'){
			if(b == 'C')
			ans4 = 0;
		}
		else{
			ans4 = 1;
		}
	}
	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}