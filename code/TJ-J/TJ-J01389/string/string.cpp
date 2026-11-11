#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N];
string s[N];
int check(string ss){
	long long cnt=0;
	long long len=ss.size();
	int tmp=0;
	for(int i=0;i<len/2;i++){
		if(ss[i]==ss[len-i-1]) tmp++;
		if(ss[i]!=ss[len-i-1]){
			cnt++;
		}
	}
	if(tmp==len/2) return -1;
	else return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long minn=1e9+5;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		minn=min(minn,a[i]);
	}
	string ss="";
	long long g=0;
	long long tmp=0;
	for(long long i=1;i<=minn;i++){
		for(int j=1;j<=n;j++){
			if(a[j]%i==0) tmp++;
			else break;
		}
		if(tmp==n) g=max(g,i);
	}
	for(int i=1;i<=n;i++) a[i]/=g;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ss+=s[i];
		}
	}
	if(check(ss)==-1) cout<<0;
	else cout<<check(ss)*g;
	//bjy
}
