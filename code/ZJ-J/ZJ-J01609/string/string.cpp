#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
	int n;
	cin>>n;
	int cnt=0;
	string s=" ";
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		cnt+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	int sum=0;
	int l=1,r=cnt;
	while(true){
		if(l==r||l>r) break;
		if(s[l]!=s[r]) sum++;
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
