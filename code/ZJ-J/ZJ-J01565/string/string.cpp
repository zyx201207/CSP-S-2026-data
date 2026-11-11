#include<bits/stdc++.h>
using namespace std;
int n;
string s[10000009];
long long x=0;
long long ans=0;
long long q;
string p[500009],m[500009];
struct zf{
	int a;
	string c;
}v[300000];
long long asd(){
	for(int i=0;i<q;i++){
		if(p[i]!=m[x-i-1]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i].a>>v[i].c;
		for(long long j=x;j<x+v[i].a;j++){
			s[j]=v[i].c;
		}
		x+=v[i].a;
	}
	q=x>>1;
	for(int i=0;i<q;i++){
		p[i]=s[i];
	}
	if(x%2==1){
		for(int i=q+1;i<x;i++){
			m[i]=s[i];
		}
	}
	else{
		for(int i=q;i<x;i++){
			m[i]=s[i];
		}
	}
	cout<<asd();
	fclose(stdin);
	fclose(stdout);
	return 0;	
}