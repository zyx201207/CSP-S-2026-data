#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=2e5+10;
int a[maxn];
char c[maxn];
long long p[maxn];
struct node{
	int a;char c;
};
vector<node> vec;
void solve(void){
	int n;cin>>n;
	string str="";
	for(int i=1;i<=n;i++){
		int a;char c;cin>>a>>c;
		for(int j=1;j<=a;j++){
			str+=c;
		}
	}
	int len=str.size();
	long long ans=0;
	for(int i=0;i<len;i++){
		if(str[i]!=str[len-1-i]){
			ans++;
		}
	}
	cout<<ans/2<<endl;
}
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int T=1;//cin>>T;
	while(T--)	solve();
	return 0;
}

