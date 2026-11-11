#include <bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	long long begin,end;
	char c;
}s[200005];
long long p=0;
int cnt=1;
void add(long long num,char c){
	s[cnt].begin = ++p;
	p+=num-1;
	s[cnt].end = p;
	s[cnt++].c=c;
//	for(int i = 1;i<=num;i++){
//		s=s+c;
//	}
}
char find(long long pp){
	for(int i = 1;i<=cnt-1;i++){
		if(pp>=s[i].begin and pp<= s[i].end)return s[i].c;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		long long num;
		char c;
		cin >> num >> c;
		add(num,c);
	}
	for(int i = 1;i<=p/2;i++){
		if(find(i)!=find(p-i+1))ans++;
	}
	cout << ans;
	return 0;
}
