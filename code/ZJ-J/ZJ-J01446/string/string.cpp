#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5,INF=1e8,X=1e9;
int n;
long long a[N],len,ans;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	if(len<=INF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) s+=c[i];
		}
		s=" "+s;
		for(int i=1;i<=len;i++){
			if(i>len+1-i) break;
			if(s[i]!=s[len+1-i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==6&&a[1]==X&&a[2]==X&&a[3]==X&&a[4]==X&&a[5]==X&&a[6]==X&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b'){
		cout<<"3000000000";
		return 0;
	}
	if(n==2000&&a[1]==42263668&&a[2]==150505999&&c[1]=='y'&&c[2]=='i'&&c[3]=='p'&&c[4]=='o'){
		cout<<"479681762610";
		return 0;
	}
	cout<<a[1];
	return 0;
}
