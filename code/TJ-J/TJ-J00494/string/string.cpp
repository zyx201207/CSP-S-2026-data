#include <bits/stdc++.h>
using namespace std;
// 注释记得去掉 检查 
const int N = 2e5+8;
struct Sl{
	long long a;
	char c;
};
Sl p[N];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans = 0;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> p[i].a >> p[i].c;
	}
	long long i=1,j=n;
	while(i<=j){
		if(p[i].a>p[j].a){
			if(p[i].c!=p[j].c)ans+=p[j].a;
			p[i].a-=p[j].a;
			j--;
		}
		else if(p[i].a<p[j].a){
			if(p[i].c!=p[j].c)ans+=p[i].a;
			p[j].a-=p[i].a;
			i++;
		}
		else{
			if(p[i].c!=p[j].c)ans+=p[i].a;
			i++,j--;
		}
	}
	cout << ans;
	
	return 0;
}
