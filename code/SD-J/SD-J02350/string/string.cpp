#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int x;
	char c;
}a[200005];
int n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
