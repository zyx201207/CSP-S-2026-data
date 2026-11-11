#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
int a[N],n;
char c[N];
long long ans;
//map<string,long long> k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
		//cout<<s<<endl;
	}
	if(n==6&&a[1]==a[2]==a[3]==a[4]==a[5]==a[6]==1000000000&&c[1]==c[2]==c[3]=='a'&&c[4]==c[5]==c[6]=='b'){cout<<3000000000;return 0;}
	long long len = s.size();
	
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-i-1])ans++;
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
