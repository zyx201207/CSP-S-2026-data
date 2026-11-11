#include<bits/stdc++.h>
using namespace std;
long long n,m[200010],ans;
char k[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>m[i]>>k[i];
	for(int i=1,j=n;i<j;){
		long long x=min(m[i],m[j]);
		if(k[i]!=k[j]) ans+=x;
		m[i]-=x;
		m[j]-=x;
		if(m[i]==0) i++;
		if(m[j]==0) j--;
	//	cout<<i<<","<<j<<":"<<(k[i]!=k[j])<<" "<<x<<endl;
	}
	cout<<ans;
	return 0;
}
