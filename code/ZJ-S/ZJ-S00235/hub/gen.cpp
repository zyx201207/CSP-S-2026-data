#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
const int N=1e6+5;
int p[N];
mt19937 rd(random_device{}());
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c=0,t=100;cout<<c<<" "<<t<<"\n";
	while(t--)
	{
		int n=rd()%20+2,B=5;cout<<n<<" "<<rd()%n+1<<"\n";
		for(int i=1;i<=n;++i)p[i]=i;
		shuffle(p+1,p+n+1,rd);
		for(int i=2;i<=n;++i)cout<<p[i]<<" "<<p[i-rd()%min(i-1,B)-1]<<"\n";
	}
	return 0;
}