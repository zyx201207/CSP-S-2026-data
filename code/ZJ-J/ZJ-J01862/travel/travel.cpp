#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
int n1,n2;
string s1,s2;
int a[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n1>>s1>>n2>>s2;
	if(n1==n2){
		a1=1;
	}
	int t1=0,t2=0;
	if(s1[0]=='0'){
		t1=s1[1]-'0';
	}else{
		t1=s1[1]-'0'+10;
	}
	if(s2[0]=='0'){
		t2=s2[1]-'0';
	}else{
		t2=s2[1]-'0'+10;
	}
	if(t1==t2&&a1==1){
		a2=1;
	}
	a[0]=1;a[1]=1;a[2]=1;a[3]=2;a[5]=2;
	if(a[s1[2]-'A']==a[s2[2]-'A']&&a2==1){
		a3=1;
	}
	if(abs(s1[2]-s2[2])==1&&a3==1){
		a4=1;
	}
	cout<<a1<<a2<<a3<<a4;
}