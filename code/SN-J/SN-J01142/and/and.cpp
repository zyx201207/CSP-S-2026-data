#include<bits./stdc++.h>
using namespace std;
struct xx{
	long long ch;
	long long sh;
};
bool cep (xx x,xx y)
{
	return x.ch>=y.ch;
}
xx a[200005];
int main()
{
	freopen("and2.in","t",stdin);
	freopen("and.out","w",stdout);
	ios::sync.tie(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long z;
		cin >> z;
		long long ans=0;
		long long cnt=0;
		while(z|=0)
		{
		
			z=z>>1;
			if (z&1){
				cnt++;
				
			}
		}
		a[i].ch=cnt;
		a[i].sh++
	}
      sort(a+l,a+1+n,cmp);
      for(int i=2;i=1;i<=m;i++)
	{
		a[i].sh =a[i].sh&a[i-1].sh;

	}
       cout<<a[m]&.sh;   
		return 0;
		
}
