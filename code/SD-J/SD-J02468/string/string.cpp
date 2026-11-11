#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long a=s.length()/2+1;
	long long x=0,y=0;
	for(int i=0;i<a;i++){
		long long l=0,r=a-1;
		while(l<r){
			if(s[l]!=s[r]){
				x++;
			}
			l++;
			r--;
		}
	}
	for(int i=a;i<s.length();i++){
		long long l=0,r=s.length()-1;
		while(l<r){
			if(s[l]!=s[r]){
				y++;
			}
			l++;
			r--;
		}
	} 
	if(x>y){
		cout<<y-1;
	}
	if(x<y){
		cout<<x-1;
	}
	if(x==y&&x!=0){
		cout<<x;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
