#include<bits/stdc++.h>
using namespace std;
int a[100001];
char s[100001];
string str; 
int in;
int zong=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
int n,k=0;
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i]>>s[i];
}
if(n<=1){
	cout<<0;
	return 0;
}
if(n==2 and s[0]==s[1]){
cout<<0;
return 0;	
}
if(n==2 and s[0]!=s[1]){
	cout<<1;
	return 0;
}
for(int i=0;i<n;i++)
	for(int j=0;j<s[i];j++)
		str+=s[i];
k=n;
int wei=0;
bool f=true;
for(int i=0;i<n/2;i++){
	if(str[i]!=str[k]){
		f=false;
		wei=i;
	}
	k--;
}
k=n;
if(f=true){
	cout<<"0";
	return 0;
}
else{
	if(wei==n/2)cout<<1;
	for(in=0;in<n/2-wei;in++){
		str[wei]=str[k-wei];
		for(int i=0;i<n/2;i++){
			if(str[i]!=str[k]){
				f=false;
				wei=i;
			}
		k--;
		}
		if(f=true){
			cout<<in;
			return 0;
		}
		else{
			zong=true;
		}
	}
}
cout<<in;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

