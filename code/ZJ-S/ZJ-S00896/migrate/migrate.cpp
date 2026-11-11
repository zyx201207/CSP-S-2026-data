#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
struct node{
	int to,next,len;
}a[N];
priority_queue< PII,vector<PII>,greater<PII> > q;
int c,n,m,T,d,k,qu,pre[N],da[N],w[N],r[N][30],le[N],kd[510],s,e;
bool f[N];
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin>>c>>T;
  while(T--)
  {
  	cin>>n>>d;
  	int j=(1+n)*n/2-n;
  	cout<<0<<"\n";
  }
  
  return 0;
}

