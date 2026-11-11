#include<bits/stdc++.h>
#define ll long long
using namespace std;
//cnm devc++!!!!!!!!!!!
struct str{
	ll non;
	char zi;
};
string s="",s2="",rsty="";
str a[200009];
int n,num=0;
int main(){
	ll ii=0,jj=0;
	stack<char> q;
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].non>>a[i].zi;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].non;j++){
			//s[ii]=a[jj].zi;
			q.push(a[jj].zi);
			
			ii++;
		}
		jj++;
	}
	ll tim=ii;
	while(!q.empty()){
		rsty[tim]=q.top();
		q.pop();
		tim--;
	}
	rsty="aabbc";
	for(int i=0;i<rsty.size();i++){
		s=rsty;
	}
	
	ll len=s.size();
	ll sum=len/2;
	for(int i=(n-1);i>=0;i--){
		for(int j=(a[i].non-1);j>=a[i].non;j--){
			s2[j]=a[i].zi;
		}
	}
	for(int i=0;i<(len/2);i++){
		if(s[i]==s2[i]){
			//do not thing!
		}
		else{
			num++;
		}
	}
	
	//continue;
	//break;
	cout<<num;
	//fclose(stdin);
	//fclose(stdout); 
	
}
