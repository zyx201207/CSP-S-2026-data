#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
string s;
bool flag1=1;
unsigned long long cnt=0;
unsigned long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		cnt+=a[i];
		for(int j=cnt-a[i];j<cnt;j++){
			s[j]=c;
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt+1-i]) flag1=0;
	}
	if(flag1){
		cout<<0;
	}
	else{
		if(cnt%2==0){
			for(int i=0;i<cnt*1.0/2;i++){
				if(s[i]!=s[cnt-i-1]) ans++;
			}
		}
		else{
			for(int i=0;i<(cnt-1)*1.0/2;i++){
				if(s[i]!=s[cnt-1-i]) ans++;
			}
		}
		cout<<ans;
	}
//	for(int i=0;i<cnt;i++) cout<<s[i];
	return 0;
}
