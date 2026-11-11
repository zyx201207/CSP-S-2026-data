#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
struct num{
	int a;
	char c;
}str[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int a1=str[l].a,a2=str[r].a;
		int am=min(a1,a2);
		if(str[l].c!=str[r].c)ans+=am;
		str[l].a-=am,str[r].a-=am;
		if(str[l].a==0)l++;
		if(str[r].a==0)r--;
	}
	cout<<ans;
	return 0;
}
