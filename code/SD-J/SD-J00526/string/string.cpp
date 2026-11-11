//string
//9:05 start B
//9:10 wa on B
//9:20 leave B
//9:53 backt B
//9:54 start B 
//0:09 parta B
//0:14 wa on B
//1:30 backt B
//1:40 write B
//1:45 wa on B
//1:46 givup B
//数据和样例使用Linux方式存储，在Windows下运行会出错
//~~（那我怎么跑大样例？）~~
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long //10^9
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ssize=0,ans=0;
	stack<char> temps;
	queue<char> s;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		int num;
		char c;
		scanf("%lld %c",&num,&c);
		for(int j=1;j<=num;++j){
			s.push(c);
			temps.push(c);
			ssize++;
		}
	}ssize=((ssize%2==0)?(ssize/2):((ssize+1)/2));
	for(int i=1;i<=ssize;++i){
		if(temps.top()!=s.front()){
			ans++;
			temps.pop();
			s.pop();
		}
	}printf("%lld",ans);
	return 0;
}
