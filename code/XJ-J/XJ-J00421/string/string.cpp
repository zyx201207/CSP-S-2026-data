#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,shu=0,zshu=0,a;cin>>n;
	string s;
	char sa;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>sa;
		zshu+=a;
		for(int j=1;j<=a;j++){
			s+=sa;
		}
	}
	if(zshu>300000000)cout<<zshu/2;
	long long sum=0;
	shu=zshu-1;
	for(int i=0;i<zshu/2;i++){
		if(s[i]!=s[shu-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
