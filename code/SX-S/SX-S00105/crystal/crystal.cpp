#include<bits/stdc++.h>
using namespace std;
#define fr(i,s,n) for(int i=s;i<=n;i++)
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    int d=a[2]-a[1];
    int k=m/d;
    int sum=0;
    int z=d;
	fr(i,1,n){
		if(k>=z){
			k-=z;
			sum++;
			z+=d;
		}
		else{
			break;
		}
	}
	cout<<sum;
    return 0;
}