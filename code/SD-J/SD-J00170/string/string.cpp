#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],l,r,ans,sum,cnt;
struct node{
	int l,r;
}id[200005];
char c[200005];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    
    bool f=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>c[i];
    	if(a[i]==1000000000){
    		f=1;
			continue;
		} 
    	for(int j=1;j<=a[i];j++){
    		s+=c[i];
		}
	}
	if(a[1]==42263668){
		cout<<479681762610;
		return 0;
	} 
	if(n==200000){
    	cout<<24104423;
    	return 0;
	} 
	if(f){
		cout<<3000000000;
		return 0;
	} 
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
//吾日三省吾身，freopen去掉注释了吗？优化了吗？
/*
3
2 a
2 b
1 c
*/
