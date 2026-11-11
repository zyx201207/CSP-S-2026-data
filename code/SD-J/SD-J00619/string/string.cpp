#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,a;
char c[N];
struct Node{
	long long fir,end;
}b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	long long len=0;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a>>c[i];
		b[i].fir=b[i].end+1;
		b[i].end=b[i].end+a;
	}
	for(int i=1;i<=n;i++){
		for(int j=b[i].fir;j<=b[i].end;j++){
			s[len]=c[i];
			len++;
		}
	}
	long long cnt=0;
	for(long long i=0;i<len;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
			s[i]=s[len-i-1]; 
		}
	}
	cout<<cnt;
	return 0;
}
