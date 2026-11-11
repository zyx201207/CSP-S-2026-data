#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num[200010];
    long long cnt;
    string s;
    long long n,nn=0;
	int t=0;
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		nn+=a;
		num[t++]=a;
		s+=c;
	}
	if(nn%2!=0)nn--;
	nn/=2;
	for(int i=0;i<nn;i++){
		if(s[i]!=s[nn-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
