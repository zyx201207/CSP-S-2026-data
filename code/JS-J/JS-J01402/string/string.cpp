#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,k=0,sum;
struct node
{
    int x;
    char c;
}f[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        node a;
        a.x=x;
        a.c=c;
        if(f[k].c==c)  f[k].x+=x;
        else f[++k]=a;
        sum+=x;
    }
    if(k==1)  cout<<0<<endl;
    else if(k==2)  cout<<min(f[1].x,f[2].x)<<endl;
    else cout<<sum/2<<endl;
	return 0;
}

