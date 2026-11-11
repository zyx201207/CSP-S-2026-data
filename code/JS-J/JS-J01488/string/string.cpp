#include<iostream>
#include<string>
#define ll long long
using namespace std;

string s;
ll n,size,cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll num;char ch;
		cin>>num>>ch;
		size+=num;
		while(num--)s+=ch;
	}
	ll mid=size>>1,l,r;
	if(size&1)l=r=mid;
	else l=mid-1,r=mid;
	for(;l>=0 && r<=size;l--,r++){
		if(s[l]!=s[r])cnt++;
	}
	cout<<cnt;
}