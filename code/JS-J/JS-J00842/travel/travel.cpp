#include<bits/stdc++.h>
using namespace std;
char n,a[5],b[5];
int t1,t2;
//string c1,s1,c2,s2;
string c1,c2;
char s1[5],s2[5],p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<5;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[t1]=s1[i];
			t1++;
		}else if(s1[i]>='A'&&s1[i]<='F'){
			p1=s1[i];
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			b[t2]=s2[i];
			t2++;
		}else if(s2[i]>='A'&&s2[i]<='F'){
			p2=s2[i];
		}
	}
	for(int i=0;i<5;i++){
		if(a[i]!=b[i]){
			cout<<0<<0<<0;
			return 0;
		}
		
	}cout<<1;
	if(p1<='C'&&p1>='A'){
		if(p2<='C'&&p2>='A'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}if((p1-p2)==1||(p2-p1)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
