#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool qs4=((s1[2]+1==s2[2])||(s1[2]-1==s2[2]));
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){

		
        cout<<1;
        
        //pre-process qs2's data;
        string s;
        s+=s1[0];
        s+=s1[1];
        string ss;
        ss+=s2[0];
        ss+=s2[1];
        
        
        //qss
		bool qs2=s==ss;
		bool qs3=((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D'));
		
        
        
        //if
        if(qs2){
        	cout<<1;
        	if(qs3){
        		cout<<1;
        		if(qs4)cout<<1;
        		else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
		

    }else cout<<"0000";//他妈的神了 两个0自动合并 我他吗输出半天整数 
    return 0;
}
