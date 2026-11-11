#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int sum=0;
	string s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
