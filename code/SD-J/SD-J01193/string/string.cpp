#include<bits/stdc++.h>
using namespace std;
/*
bool rever(string s,int cnt){
	for(int i=0;i<s.size();i++){
		if(s[i]==s[cnt-i+1]) continue;
		else return 0;
	}
	return 1;
	
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;
	string s;char c[n];

	long long a[n];int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<a[i];j++){
			if(c[i]>='a' && c[i]<='z')	s[i]=c[i];
		
		}	
	}
	int cs=0;
	/*
	while(rever(s,cnt)!=0){
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[cnt-i+1]) cs+=1;s[cnt-i+1]=s[i];
		}
	}*/
	for(int i=0;i<cnt/2+1;i++){
		if(s[i]!=s[cnt-i+1]) cs+=1;
	}
	cout<<cs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

