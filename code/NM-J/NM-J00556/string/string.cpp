#include <bits/stdc++.h>
using namespace std;
char s[100000000],fs[100000000],c;
long long n,ans,a,cnt;
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[ans]=c;
			ans++;
		}
	}
	cnt=ans/2;
	while(1==1) {
		if(cnt==0){
			cnt=-1;
			break;
		}
		if(s[cnt]==s[ans-cnt])cnt--;
		else break;
	
	}
	cout<<cnt+1;

	return 0;
}
