#include<bits/stdc++.h>
using namespace std;
int cnt[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b,l,h=0;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	string S;
	l=0;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		h+=cnt;
		cin>>S[i];
	}
	l=cnt[1]+cnt[2];
	if(S[1]==S[2]){
		cout<<0;
		return 0;
	}
	if(cnt[1]>=cnt[2]){
		b=cnt[1];
	}
	else{
		b=cnt[2];
	}
	int ch=l-b;
	if(b>=l/2){
		cout<<ch;
		return 0;
	}
	else{
		int m=h/2;
		cout<<m;
		return 0;
	}
}
