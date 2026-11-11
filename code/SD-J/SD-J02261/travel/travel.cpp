#include<bits/stdc++.h>
using namespace std;

//È¥×¢ÊÍ

#define endl '\n'
char st1,st2;
int c1,c2,s1,s2,p1,p2,lr1,lr2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>c1>>p1>>st1>>c2>>p2>>st2;
	//cout<<c1<<p1<<st1<<c2<<p2<<st2;
	s1=st1-'A'+1;
	s2=st2-'A'+1;
	if(s1==1||s1==2||s1==3)lr1=1;
	else lr1=2;
	if(s2==1||s2==2||s2==3)lr2=1;
	else lr2=2;
	//cout<<" "<<s1<<" "<<s2<<endl;
	//cout<<" "<<lr1<<" "<<lr2<<endl;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2)cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&lr1==lr2)cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&lr1==lr2&&abs(s1-s2)==1)cout<<1;
	else cout<<0;
	
	return 0;
} 
//freopen("travel.in","r",sdin);
//freopen("travel.ans","w",stdot);
//freopen("trael.int","r",pstdin);
//freopen("travl.out","w",gunmu);
//freopen("trvel.114514","r",stdin);
//freopen("travl.ut","w",stdout);
//114514#include<bits\stdc++.h>#include<bits\stdc++.h>#include<bits\stdc++.h>


