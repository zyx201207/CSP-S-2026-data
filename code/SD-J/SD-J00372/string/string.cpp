#include<bits/stdc++.h>
using namespace std;
const long long q=2*1e5+10;
char b[q];
long long s[q];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,af;
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>b[i];
		for(int j=0;j<s[i];j++){
			a=a+b[i];
		}
	}
	int j=0;
	for(int i=a.size()-1;i>=0;i--){
		af[j]=a[i];
		af+=af[j];
		j++;
	}
	int cnt=0;
	for(int i=0;i<=a.size();i++){
		if(af[i]!=a[i]){
			cnt++;
		}
	}cout<<cnt/2;
	return 0;
}
