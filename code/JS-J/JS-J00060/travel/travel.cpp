#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	int t1=1,t2=1,t3=1,t4=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			t1=0;
		}
	}
	if(t1==0){
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			t2=0;
		}
	}
	if(t2==0){
		cout<<t1<<0<<0<<0;
		return 0;
	}
	if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='D')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]<='C')){
		t3=0;
	}
	if(t3==0){
		cout<<t1<<t2<<0<<0;
		return 0;
	}
	if(abs(s2[2]-s4[2])!=1){
		t4=0;
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
