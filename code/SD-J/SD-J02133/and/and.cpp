#include<bits/stdc++.h>
using namespace std;
int a[200005];
int m,n;
int f(int y,int x)
{
	if(y==0)
	return x;
	int max=0,maxn;
	for(int i=0;i<n;i++){
		if(max<=(a[i]&x))
		{
			max=(a[i]&x);
			maxn=i;
		}
	}
	a[maxn]=0;
	f(y-1,max);
	}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<f(m, pow(2,31)-1);
	return 0;
}

