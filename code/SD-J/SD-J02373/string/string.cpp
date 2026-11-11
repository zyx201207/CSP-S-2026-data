#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
const int N=2e5;
struct st{
	int a;
	char c;
}s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=1,j=n;i<=j;){
		int k=min(s[i].a,s[j].a);
		if(s[i].c!=s[j].c){
			ans+=k;
		}
		s[i].a-=k;
		s[j].a-=k;
		if(s[i].a<=0){
			i++;
		}
		if(s[j].a<=0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
