//wangyihao tieyizhong SN-J00729
#include<bits/stdc++.h>
using namespace std;
string s,m;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	long long n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<n;i++){
		m[i]=s[n-i];
	}
	if(m==s){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
