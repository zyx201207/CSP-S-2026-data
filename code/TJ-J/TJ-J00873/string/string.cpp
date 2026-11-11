#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	bool flag=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	string s,s1,s2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[j]=c[i];
			cout<<s[j]<<' ';
		}
	}
	for(int i=1;i<=sum;i++){
		s1[i]=s[i];
		cout<<s[i]<<' '<<s1[i]<<'\n';
	}
	for(int i=sum;i>=1;i--){
		for(int j=1;j<=sum;j++){
			s2[j]=s[i];
		}
	}
	for(int i=1;i<=sum;i++){
		if(s1[i]!=s2[i]){
			flag=0;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
