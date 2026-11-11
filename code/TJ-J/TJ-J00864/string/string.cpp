#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a,b;
long long n,s[N],sum=0;
char v[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>v[i];
		for(int j=1;j<=s[i];j++){
			a.push_back(v[i]);
		}
	}
	b=a;
	reverse(a.begin(),a.end());
	if(b==a){
		cout<<0;
		return 0;
	}
	else {
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i])sum++;
		}
	}
	cout<<sum/2;
	return 0;
} 
