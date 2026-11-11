#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" ";
	int siz=0;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		siz+=x;
		for(int j=1;j<=x;j++){
			s=s+ch;
		}
	}
	//1~siz
	int mid=(siz+1)/2;
	for(int i=1;i<=mid;i++){
		if(s[mid-i+1]!=s[mid+i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
}
