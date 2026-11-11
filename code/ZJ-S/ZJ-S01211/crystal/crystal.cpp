#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e5+5;
int a[N];
int b[N];
int y=1;//B
void CF(int n){
	//0 1 2
	//1 2
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]!=b[i-1]&&i!=1) y=0;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
    long long n,m;
    cin>>n>>m;
    int x=1;//A
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=i) x=0;//A
	}
	long long sum=0;
	sort(a+1,a+1+n);
	CF(n);
    long long cnt2=0;
    long long g2=0;
	for(long long i=0;i<n;i++){
		cnt2=0;
		g2=0;
		for(long long j=i+1;j<=n;j++){
			g2++;
			cnt2+=b[j]*g2;
			if(cnt2>m){
				sum=max(j-i,sum);
				break;
			}
		}
	} 
    cout<<sum;
     
	return 0;
}

