#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],b[30005];
bool check_in(stack<long long> s,long long x){
	long long len=s.size();
	while(!s.empty()){
		if (x==s.top())
			return 1;
		s.pop();
	}
	return 0;
}
int main(){
	//I love NOI,能给个满分吗,第四题比以前简单，我第一次写出来一点，但时间复杂度太高 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	stack<long long> s;
	for (long long i=1;i<=n;i++)
		cin>>a[i];
	for (long long i=1;i<=n;i++){
		for (long long j=i;j<=n;j++){
			if (check_in(s,a[j])){
				while(s.top()!=a[j])
					s.pop();
				s.pop();
			}
			s.push(a[j]);
		}
		while (!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for (long long i=1;i<=m;i++)
		cout<<b[i]<<' ';
	return 0;
}/*这是我第三次参加csp-j了，应该也是最后一次，前两次就差15分，3个测试点数据就一等奖了，今年T2有点难，我不会退步了吧？
现在我估分200左右，不会还得不了一等奖了吧？真希望分能低一点 */ 
