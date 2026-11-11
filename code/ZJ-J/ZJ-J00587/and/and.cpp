#include<iostream>
#include<queue>
using namespace std;
const int N=2e5+10;
unsigned long long n,m,s;
priority_queue<unsigned long long>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		unsigned long long x;
		cin>>x;
		q.push(x);
	}
	s=q.top();
	q.pop();
	for(int i=2;i<=m;i++){
		s&=q.top();
		q.pop();
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
