#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int x;
		string c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	int len=s.size();
	int len2=len/2;
	long long sum=0;
	for(int i=len2;i<=len;i++){
		if(s[len-i-1]!=s[i]) sum++;
	}
	cout<<sum;
    return 0;
}
