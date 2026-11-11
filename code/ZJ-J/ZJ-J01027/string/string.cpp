#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1;i<=n;i++){
		while(a[i]--){
			s+=c[i];
		}
	}
	int sum=0,cnt=0;
	int len=s.length();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			sum++;
		}	
	}
	for(int i=len/2;i<len;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	int mi=min(sum,cnt);
	cout<<mi;
	return 0;
}

