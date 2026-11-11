#include<bits/stdc++.h>
using namespace std;
long long tong[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long long n;
long long a;
char c;
long long maxx=0;
string s;
bool f(string x){
	for(int i=0;i<=x.size()/2;i++){
		if(x[i]!=x[x.size()-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		tong[(c-'a')+1]+=a;
		if(tong[(c-'a')+1]>maxx){
			maxx=tong[(c-'a')+1];
		}
		s+=c*a;
	}
	if(f(s)==true){
		cout<<0;
	}else{
		cout<<maxx;
	}
	return 0;
}
