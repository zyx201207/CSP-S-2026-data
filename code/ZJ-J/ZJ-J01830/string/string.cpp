#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	long long cnt;
}a[200005];
string st;
long long n,cnt;
bool q1,q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].cnt);
		cin>>a[i].c;
		if(a[i].cnt!=a[i-1].cnt&&i!=1) q1=1;
		if(a[i].c!=a[i-1].c&&i!=1) q2=1;
	}
	if(q1==0){
		for(int i=1;i<=n/2;i++){
			if(a[i].c!=a[n-i+1].c) cnt+=a[i].cnt;
		}
		cout<<cnt;
		return 0;
	}
	if(q2==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=a[i].cnt;j++) st+=a[i].c;
	long long st_len=st.size();
	for(int i=0;i<=st_len/2;i++){
		if(st[i]!=st[st_len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}

/*
9223372036854775808
200000000000000

*/