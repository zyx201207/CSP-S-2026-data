#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans;
struct st{
	int a;
	char c;
} d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].c;
		for(int j=1;j<=d[i].a;j++){
			s+=d[i].c;
		}
		d[i].a+=d[i-1].a;
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
 
