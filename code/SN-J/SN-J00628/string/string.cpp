//zhangzhitong xianshidibashijiuzhongxue SN-J00628
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
struct node{
	ll b;
	char c;
}a[N];
int n,ans;
ll cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
		cnt+=a[i].b;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].b;j++){
			s+=a[i].c;
		}
	}
	int l=0,r=cnt-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;r--;
	}
	cout<<ans;
	return 0;
}
	
