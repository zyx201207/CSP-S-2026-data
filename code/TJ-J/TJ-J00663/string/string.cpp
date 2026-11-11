#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n,a,cnt=0;
	string b,c;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		for(int j=1;j<=a;j++){
			b+=c;
		}
	}
	long long len=b.size();
	long long nel=len;
	for(int k=0;k<len/2;++k){
		if(b[k]!=b[nel-1])
		{
			cnt++;
			nel-=1;
		}
	}
	cout << cnt;
	return 0;
}
