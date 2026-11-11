#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	string s="";
	cin>>n;
	int l;
	char t;
	for(int i=0;i<n;i++){
		cin>>l>>t;
		while(l--)
			s+=t;
	}
	string ss="";
	int w=s.size();
	for(int i=w-1;i>=0;i--)
		ss+=s[i];
	for(int i=0;i<w;i++)
		if(s[i]!=ss[i]){
			sum++;
			ss[w-i-1]=ss[i];
		}
	cout<<sum;
}