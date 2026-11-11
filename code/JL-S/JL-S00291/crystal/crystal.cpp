#include <bits/stdc++.h>
using namespace std;
int a[10005],n,m,h;
int main()
{
    freopen("crystal.in","r","stdin")
    freopen("crystal.out","w","stdout")
    cin>>n>>m;
    cin>>h;
    for(int i=1;i<=n;i++)
    {
		while(h>1)
		{
			a[i]+=h;
		}
	}
    cout<<h<<endl;
    
    return 0;
}
