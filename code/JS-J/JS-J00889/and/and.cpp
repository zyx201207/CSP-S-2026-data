#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1000;
long long n,m,a[N],x=1,cnt,c[N],d;
bool b[N],e=false;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		b[i]=true;
	}
	for(int i=1;i<=31;i++){
		x*=2;
	}
	d=x-1;
	for(long long i=x;i>=1;i/=2){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=i){
				a[j]-=i;
				cnt++;
			}
		}
		if(cnt>=m){
			e=true;
			for(int j=1;j<=n;j++){
				if(a[j]>=i){
					a[j]-=i;
				}
				else b[j]=false;
			}
		}
		else if(e){
			for(int j=1;j<=n;j++){
				if(b[j]){
					d&=c[j];
				}
			}
			break;
		}
	}
	cout<<d;
	return 0;
}
