#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
char s['9'];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	int c,d;
	int f=0,f1=0,f2=0;
	char ss,s1;
	cin>>a>>c>>ss>>b>>d>>s1;
	
	if(a==b){
		f=1;
		s['0']='1';
	}else{
		s['0']='0';
	}
	if(c==d&&f){
		f1=1;
		s['1']='1';
	}else{
		s['1']='0';
	}
	int p='A'+3;
	if(ss=='C'&&s1=='D'){
		s['2']='0';
	}
	else if(c==d&&(ss-'A')<=p&&(s1-'A')<=p&&f&&f1){
		f2=1;
		s['2']='1';
	}else if(c==d&&ss=='D'&&s1=='F'&&f&&f1){
		f2=1;
		s['2']='1';
	}else{
		s['2']='0';
	}
	int sum=(ss-'A')-(s1-'A');
	int sum1=(s1-'A')-(ss-'A');
	if(ss=='C'&&s1=='D'){
		s['3']='0';
	}else if(ss=='D'&&s1=='F'){
		s['3']='1';
	}else if(ss>s1&&sum==1&&f&&f1&&f2){
		s['3']='1';
	}else if(ss<s1&&sum1==1&&f&&f1&&f2){
		s['3']='1';
	}else{
		s['3']='0';
	}
	cout<<s['0']<<s['1']<<s['2']<<s['3'];
	return 0;
}
