#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	bool f=true;
	int b=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=b){
			f=false;
		}
	}
	if(f=true){
		for(int i=1;i<=n;i++){
			a[i]=1;
		}
	}
	string s={};
	for(int i=1;i<=n;i++){
		int m=a[i];
		for(int j=1;j<=m;j++){
			s+=c[i];
		}
	}
	int ls=s.size();
	long long num=0;
	for(int i=0;i<ls;i++){
		if(s[i]!=s[ls-1-i]){
			s[i]=s[ls-1-i];
			num++;
		}
	}
	if(f=true){
		cout<<num*b;
	}
	else{
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}