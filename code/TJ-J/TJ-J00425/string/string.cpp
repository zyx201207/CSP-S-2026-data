#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,q=0,m=1;
	string s;
	char b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[0]!=s[i]){
			m=0;
			break;
		}
		m=1;
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			int x=0,y=s.size()-1;
			if(s[x]!=s[y])
				q++;
				if(x==s.size()/2&&y==s.size()/2+1)
				break;
		}
		cout<<q;
	}
	else if(s.size()%2==1){
		for(int i=0;i<s.size()/2;i++){
			int x=0,y=s.size()-1;
			if(s[x]!=s[y])
				q++;
				if(x==s.size()/2&&y==s.size()/2+2)
				break;
		}
		cout<<q;
	}
	fclose(stdin);
	fclose(stdout);
}
