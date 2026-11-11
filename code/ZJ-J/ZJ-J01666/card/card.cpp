//#include<bits/stdc++.h>
//using namespace std;
//string c1,s1,c2,s2;
//string ans="0000";
//int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	cin>>c1>>s1>>c2>>s2;
//	if(c1==c2){
//		ans[0]='1';
//		if(s1[0]==s2[0]&&s1[1]==s2[1]){
//				ans[1]='1';
//				if(!(s1[2]>'C'&&s2[2]<='C')){
//					ans[2]='1';
//					if((s1[2]<='C'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1)||(s1[2]>='D'&&s2[2]>='D'&&abs(s1[2]-s2[2])==2)){
//						ans[3]='1';
//					}
//				}
//		}
//	}
//	cout<<ans;
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=262143,c;
	while(x){
		x&=x-1;
		c++;
	}
	cout<<c-1;
	return 0;
}
