#include<bits/stdc++.h>
using namespace std;
long long a[100086];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s;
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	cout<<sum/2;
	return 0;
}
