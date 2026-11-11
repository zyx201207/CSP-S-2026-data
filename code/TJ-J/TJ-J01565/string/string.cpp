#include<bits/stdc++.h>
using namespace std;
char t[100010];
int y[100010];
int pd(string s){
	string ss="";
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	if(s==ss)return 1;
	else return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>y[i]>>t[i];
	}
	int h=0;
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=y[i];j++){
			h++;
			s+=t[i];	
		}
	}
	if(pd(s)){
		cout<<0;
		return 0;
	}else{
		if(n==2){
			if(y[1]>y[2]){
				cout<<y[2];
				return 0;
			}else{
				cout<<y[1];
				return 0;
			}
		}
	}
	return 0;
}
