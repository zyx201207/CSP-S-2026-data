#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,cs=0;
	cin>>n;
	long long a[n+1];
	char c[n+1];
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int p;
	if(s.size()%2==0){
		p=s.size()/2;
	}else{
		p=s.size()/2+1;
	}
	for(int i=0;i<=p;i++){
		if(s[i]!=s[s.size()-1-i]){
			cs+=1;
		}
	}
	cout<<cs;
	return 0;
}
