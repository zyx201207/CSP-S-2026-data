#include<bits/stdc++.h>
using namespace std;
struct duan{
	unsigned long long ll;
	string w;
};
unsigned long long n,len,sum;
string s;
duan a[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ll>>a[i].w;
		for(int j=1;j<=a[i].ll;j++){
			s+=a[i].w;
		}
	}
	len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[n-i+1])sum++;
	}
	cout<<sum;
	return 0;
} 
