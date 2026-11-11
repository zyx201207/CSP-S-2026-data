#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
const int N=1e6+5;
int a[N];
mt19937 rd(random_device{}());
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c=0,t=100;cout<<c<<" "<<t<<"\n";
	while(t--)
	{
		int n=rd()%100+1,w=1<<rd()%3;cout<<n<<" "<<rd()%(20)+1<<"\n";
		for(int i=1;i<=n;++i)a[i]=rd()%w+1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)cout<<a[i]+i<<" \n"[i==n];
	}
	return 0;
}