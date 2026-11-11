#include<bits/stdc++.h>
using namespace std;
int n=0,cnt=0,k=0;
long long a[100000000];
char c[10000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
		}
	k=s.size();
	for(int i=0;i<k;i++){
		for(int j=k-1;j>=0;j--){
		if(s[i]!=s[j]) cnt++;
		if(i==j||j>i) break;
		}
}
	cout<<cnt/2;
	return 0;
}

