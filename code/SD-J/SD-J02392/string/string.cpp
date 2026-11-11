#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
string b[N];
long long n;
string s;
long long cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		cnt+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}	
	bool flag=0;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) flag=1;
	}	
	if(!flag){
		cout<<0;
		return 0;
	} 
	if(cnt&1){
		long long t=cnt/2+1;
		int j=0;
		for(int i=t;i<s.size();i++){
			j++;
			if(s[i]!=s[i-2*j]) ans++;
			else continue;
		}
	}else{
		long long t=cnt/2;
		int j=0;
		for(int i=t;i<s.size();i++){
			j++; 
			if(s[i]!=s[i-2*j+1]) ans++;
			else continue;
		}
	}
	cout<<ans;
	return 0;
}
