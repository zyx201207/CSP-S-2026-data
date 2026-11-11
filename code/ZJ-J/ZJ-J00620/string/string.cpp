#include<bits/stdc++.h>
#define int long long
//68pts
using namespace std;
int n;
int a[200001];
char c[200001];
string s;
int sum;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		int l=s.size();
		for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
		cout<<ans;

}
