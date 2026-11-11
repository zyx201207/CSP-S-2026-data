#include<bits/stdc++.h>
using namespace std;
const int N=1e5*3;
int a[N];
char b[N];
string m;
int cnt,p,o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=9;i++){
		for(int y=1;y<=n;y++){
			if(a[i]%10==0){
				cnt++;
			}
		}
		if(cnt==n){
			cnt=0;
			num*=10;
			for(int y=1;y<=n;y++){
				a[i]/=10;
			}
		}
		else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int y=1;y<=a[i];y++){
			m[++p]=b[i];
		}
	}
	string s="",s1="";
	for(int i=1;i<=p/2;i++){
		s[i]=m[i];
	}
	for(int i=p/2;i<=m.size();i++){
		s1[++o]=m[i];
	}
	reverse(s.begin(),s.end());
	if(s==s1){
		cout<<"0000"<<s<<" "<<s1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

