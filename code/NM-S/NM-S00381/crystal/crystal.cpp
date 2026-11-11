#include<bits/stdc++.h>
using namespace std;
int b (int d,int e[10001])
{
	int ans = 0,bns=0,cns=0;
	for (int j = d;j<=1;j-=bns){
		cns++;
	for (int i = d;i<=1;i-=cns)
	{
		e[i]++;
		if(e[i]==e[i+1])
		{
			bns++;
			ans++;
			break;
		}
		
	}
	return ans;
}
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
int n,m,a[10001];
   cin>>n>>m;
   for(int i = 1;i<=n;i++)
   {
	   cin >> a[i];
   }
   sort (a,a+n);
   cout << b(m,a);
    return 0;
}
