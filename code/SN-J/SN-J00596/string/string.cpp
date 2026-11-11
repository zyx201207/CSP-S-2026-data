#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,l[N],r[N],ans;
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1,cnt;i<=n;i++){
		cin>>cnt>>s[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+cnt-1;
	}
	int i=1,j=n,p=r[n];
	while(i<j){
		while(l[j]>r[n]-r[i]+1){
			if(s[j]!=s[i]) ans+=p-l[j]+1;
			j--;
			p=r[j];
		}
		int q=r[n]-r[i];
		if(s[j]!=s[i]) ans+=p-q;
		p=q;
		if(p<l[j]) j--;
		i++;
	}
	cout<<ans;
	return 0;
}
