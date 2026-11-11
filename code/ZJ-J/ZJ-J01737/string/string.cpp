#include<bits/stdc++.h>
using namespace std;
int b[200001];
string c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,a;
	int n,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		for(long long j=0;j<b[i];j++){
			s+=c[i];
		}
	}
	for(long long i=s.size()-1;i>=0;i--){
		a+=s[i];
	}
	for(ilong long i=0;i<s.size();i++){
		if(a[i]!=s[i])sum++;
	}
	cout<<sum/2;
}

