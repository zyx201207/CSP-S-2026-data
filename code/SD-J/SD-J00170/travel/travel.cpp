#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
string ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	ans+="1";
    	if(s1[0]==s2[0] && s1[1]==s2[1]){
    		ans+="1";
    		if((s1[2]>='D' && s2[2]>='D') || (s1[2]<'D' && s2[2]<'D')){
    			ans+="1";
    			if(s1[2]+1==s2[2] || s2[2]+1==s1[2])ans+="1",cout<<ans;
    			else cout<<"1110";
			}else cout<<"1100";
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
//吾日三省吾身，freopen去掉注释了吗？优化了吗？
 
