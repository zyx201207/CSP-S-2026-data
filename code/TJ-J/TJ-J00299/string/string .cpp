#include<bits/stdc++.h> 
using namespace std;
string s,s2,s3;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,k=0,c=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		int x;
		string s1;
		cin>>x>>s1;
		k+=x;
		for(int j=1;j<=x;j++){
			s+=s1;
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<=k/2;i++){
		s2+=s[i];
	}
	//string s3="";
	long long y=0;
	for(int i=k-1;i>=k/2;i--){
		//int y=0;
		if(s[i]!=s2[y]){
			c++;
		}
		//cout<<c<<" ";
		//cout<<s[i]<<endl<<s2[y]<<endl;
		//cout<<k<<endl;
		y++;
	}
	cout<<c;
	return 0;
}
