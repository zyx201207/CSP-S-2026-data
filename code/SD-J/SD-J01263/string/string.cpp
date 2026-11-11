#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e3+10;
struct node{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].c;
		}
	}
	int ans=0;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
//			cout<<s[l]<<" "<<s[r]<<endl;
		}
		l++,r--;
	}
	cout<<ans;
	return 0; 
}

/*
                 
2
2 a
3 a

3
2 a
2 b
1 c

*/

