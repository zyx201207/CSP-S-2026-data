//相博然 西安辅轮中学 SN-J00677
#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,ans;
char x;
vector<char> v;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>x;
    	for(int i=1;i<=a[i];i++) v.push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=v[n-i+1]) ans++;
	}
    cout<<ans;
	return 0;
}
