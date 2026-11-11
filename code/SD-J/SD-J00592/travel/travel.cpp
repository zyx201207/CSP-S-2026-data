#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[2],a=0,b=0,q=0;
	char s1[10],s2[10];
	cin>>c[0]>>s1>>c[1]>>s2;
	
	if(c[0]==c[1]){
		cout<<1;
		a++;
	}else{
		cout<<0;
	}
	
	if(a==1){
		if(int(s1[0]-48)*10+int(s1[1]-48)==int(s2[0]-48)*10+int(s2[1]-48)){
			cout<<1;
			b++;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	if(b==1){
		if(max(s1[2],s2[2])-min(s1[2],s2[2])<3 and s1[2]!='D' and s2[2]!='D' and s1[2]!='F' and s2[2]!='F'){
			cout<<1;
			q++;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	if(q==1){
		int n1=max(int(s1[0]-48)*10+int(s1[1]-48),int(s2[0]-48)*10+int(s2[1]-48)),n2=min(int(s1[0]-48)*10+int(s1[1]-48),int(s2[0]-48)*10+int(s2[1]-48));
		if(n1-n2<=1){
			if(max(s1[2],s2[2])-min(s1[2],s2[2])<=1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
