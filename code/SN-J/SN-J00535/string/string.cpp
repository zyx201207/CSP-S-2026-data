#include<bits/stdc++.h>
using namespace std;
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a+=y;
		}
	}
	s=a;
	reverse(a.begin(),a.end());
	long long sum=1;
	for(int i=0;i<a.size();i++){
		if(s[i]!=a[i]) sum++;
	}
	sum/=2;
	cout<<sum<<endl;  
	return 0;
}

