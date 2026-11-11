#include<bits/stdc++.h>
#define LL long long
const int N=2e5+10;
using namespace std;
LL a[N],n,ans;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	LL len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-i-1])ans++;
		if(i==len-i-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
