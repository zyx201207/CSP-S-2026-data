//hezhuchen延安新区第一中学SN-J00632 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,cnt=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		char y;
		cin>>y;
		num+=x;
		for(int i=0;i<x;i++){
			s+=y;
		}
	}
	long long m=(num/2)+1;
	string s1,s2;
	for(int i=m;i<=num-1;i++){
		s1+=s[i];
	}
	for(int i=s1.size()-1;i>=0;i--){
		s2+=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]!=s[i])
		{
			cnt++;
		}
	}
	//cout<<s<<endl<<s1<<endl<<s2<<endl;
	cout<<cnt;	
	return 0;
}
