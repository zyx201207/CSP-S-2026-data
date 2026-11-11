#include <bits/stdc++.h>
using namespace std;
const int N=2e5+50;
deque <char> q;
int n;
long long len,cnt;
string s=" ";
struct node{
	int x; char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
		len+=a[i].x;
	}
	int l=1,r=len;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
