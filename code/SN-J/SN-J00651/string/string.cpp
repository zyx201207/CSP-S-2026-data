//马知遥 西安交通大学附属中学 SN-J00651 
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int x;
//struct node{
//	int l,r,c;	
//}d[10000005];
//signed main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>x>>d[i].c;
//		d[i].l=d[i-1].r+1;
//		d[i].r=d[i-1].r+x;
//	}
//	for(int i=1,j=n;i<j;){
//		
//	}
//}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	s="#"+s;
	int ans=0;
	for(int i=1;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
}
//每次向后跳，O(n) 
