#include<bits/stdc++.h>
using namespace std;
int s,f;
char a[1000000000];
bool m(char p[]){
	for(int i=1;i<=s/2;i++){
		if(p[i]!=p[s-i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long b;
	char c;
	cin>>n;
	int j=1,k=j;
	for(int i=1;i<=n;i++){
		cin>>b>>c;
		for(;j<=k+b;j++){
			a[j]=c;
		}
		s+=b;k=j;
	}
	for(int i=1;i<=26;i++){
		for(int j=1;j<=s;j++){
			if(a[j]=='z'){
				a[j]=='a';
			}
			else{
				a[j]+=1;
			}
			f+=1;
			if(m(a)==true){
				cout<<f<<endl;
				return 0;
			}
		}
	}
	return 0;
}
