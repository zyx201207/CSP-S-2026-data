#include<bits/stdc++.h>
using namespace std;
long long n,s1[10000000],k,sum;
char z[10000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>z[i];
		for(long long j=1;j<=s1;j++){
			s+=z[i];
		}
	}
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-1-k]){
			sum++;
		}
		k++;
	}
	cout<<sum;
	return 0;
}
