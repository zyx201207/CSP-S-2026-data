//09:14 过所有样例 

#include<bits/stdc++.h>
using namespace std;

#define int long long

char l[5]={
	'D','F'
};

char r[5]={
	'A','B','C'
};

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c1,c2;
	string s1,s2;
	
	cin>>c1>>s1>>c2>>s2; 
	
//	cout<<"\n-------------------1------------\n";
	
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	//--------------------------------------
	
//	cout<<"\n-------------------2------------\n";
	
	if(c1!=c2){
		cout<<"0";
	}
	else{
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	
	//--------------------------------------
	
//	cout<<"\n-------------------3------------\n";
	
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"0";
	}
	else if(c1!=c2){
		cout<<"0";
	}
	else{
		bool f1=0,f2=0;
		bool acc=1;
		
		for(int i=0;i<=2;i++){
			if(r[i]==s1[2]){
				f1 = 1;
			}
			
			if(r[i]==s2[2]){
				f2 = 1;
			}
		}
		
		if(f1&&f2){
			cout<<"1";
		}
		else{
			acc = 0;
		}
		
//		cout<<f1<<" "<<f2<<"\n";
		
		f1 = 0;
		f2 = 0;
		
		for(int i=0;i<=1;i++){
			if(l[i]==s1[2]){
				f1 = 1;
			}
			
			if(l[i]==s2[2]){
				f2 = 1;
			}
		}
		
		if(f1&&f2){
			if(!acc){
				cout<<"1";
			}
		}
		else{
			if(!acc){
				cout<<"0";
			}
		}
	}
	
	//-----------------------------
	
//	cout<<"\n-------------------4------------\n";
	
	if(s1[2]>s2[2]){
		char t=s2[2];
		
		s2[2] = s1[2];
		s1[2] = t;
	}
	
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"0";
		
		exit(0);
	}
	else if(c1!=c2){
		cout<<"0";
		
		exit(0);
	}
	
	bool flag=0;
	
	for(int i=0;i<=1;i++){
		if(s1[2]+1==s2[2]&&s1[2]==r[i]){
			cout<<"1\n";
			
			flag = 1;
		}
	}
	
	if(s1[2]=='D'&&s2[2]=='E'){
		if(!flag){
			cout<<"1\n";
		}
	}
	else{
		if(!flag){
			cout<<"0\n";
		}
	}
	
	return 0;
}

//Trick||Treat!
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//int mian(){
//迷惑行为大赏 
