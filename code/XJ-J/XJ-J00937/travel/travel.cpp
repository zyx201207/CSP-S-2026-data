#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool n,n1;
int t1=0,t2=0,t3=0,t4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			t1=0;
			n=false;
			break;
		}else{
			t1=1;
			n=true;
		}
	}
	if(n!=false&&s1[1]==s2[1]){
		t2=1;
	}else{
		t2=0;
	}
	
	if((n!=false&&s1[2]<='C'&&s2[2]<='C'&&t2==1)||(n!=false&&s1[2]>'C'&&s2[2]>'C'&&t2==1)){
		t3=1;
		n1=true;
    }else{
    	t3=0;
    	n1=false;
	}
	if((n!=false&&n1!=false&&s1[2]-1==s2[2]&&t2==1)||(n!=false&&n1!=false&&s1[2]+1==s2[2]&&t2==1)){
		t4 =1;
	}else{
		t4=0;
	}
	if(n=true){
		cout<<t1<<t2<<t3<<t4;
	}
	
	return 0;
} 
