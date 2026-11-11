#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt,sum;
char c;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
