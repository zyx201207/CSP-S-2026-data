#include<bits/stdc++.h>
using namespace std;
int n,t1[100001],t3=1,ans,t4;
char s[2000000001],t2;
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>t1[i]>>t2;
		t4=t1[i];
		for(int i=t3;i<t3+t4;i++){
			s[i]=t2;
			t3++;
			t4--;
		}
	}
	for(int i=1;i<=n/2;i++) if(t1[i]==t1[n+1-i]) flag=true;
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=(t3-1)/2;i++) if(s[i]!=s[t3-i]) ans++;
	cout<<ans;
	return 0;
}
