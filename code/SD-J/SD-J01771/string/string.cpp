#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
struct node{
	int x;
	char c;
}a[N];
int n,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	system("fc string6.out string6.ans");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].c;
	} 
	for(int i=0;i<n;i++){
		s[i]=a[i].c;
	} 
	string s1;
	for(int i=s.size();i>0;i--){
		s1[i]=s[i];
	} 
//	for(int i=0;i<n;i++){
//		
//	} 
	for(int i=0;i<n;i++){
//		if(s==s1){
//			break;
//		} 
		if(s[i]!=s[n-i+1]){
			ans++;
		} 
	} 
	cout<<ans;
	return 0;
} 
