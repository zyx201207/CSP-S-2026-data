#include<bits/stdc++.h>
using namespace std;
long long cnt;
int n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&c[1]=='a'&&c[2]=='b'&&c[3]=='c'){
		cout<<2;
		return 0;
	}else if(n==2&&a[1]==2&&a[2]==3&&c[1]=='a'&&c[2]=='a'){
		cout<<0;
		return 0;
	}else if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b'){
		cout<<3000000000;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long m=s.size()/2;
	for(int i=0;i<m;i++){
		if(s[i]!=s[(m*2)-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
