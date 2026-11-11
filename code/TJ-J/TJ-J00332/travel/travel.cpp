#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10],ans[10];
int i=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<4;i++) ans[i]='0';
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
//		i++;
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if(!((s1[2]<='C')^(s2[2]<='C'))){
				ans[2]='1';
				if(abs(s1[2]-s2[2])==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
//	for(int i=0;i<4;i++){
//		cout<<ans[i];
//	}
//cout<<c1<<s1<<c2<<s2;
	
	return 0;
} 
