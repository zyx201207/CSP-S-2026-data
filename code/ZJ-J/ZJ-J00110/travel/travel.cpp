#include <iostream>
using namespace std;
#define sch(a,b) (x1==a&&x2==b||x1==b&&x2==a)
//head

int c1,c2,s1,s2;
char x1,x2;
//val

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
	}else if(s1!=s2){
		cout<<1000;
	}else{
		cout<<11;
		if(sch('A','B')||sch('A','C')||sch('B','C')||sch('D','F')){
			cout<<1;
			if(!sch('A','C')) cout<<1;
			else cout<<0;
		}else{
			cout<<0<<0;
		}
	}
	
	return 0;
}
