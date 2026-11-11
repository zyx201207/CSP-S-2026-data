#include<bits/stdc++.h>
using namespace std;
long long n,m,l,a[108888],d[108888];
map<int,int> q;
bool f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=0;
		for(int j=i;j<=n;j++){
			f=0;
			for(int b=l;b>=1;b--){
				if(a[j]==d[b]){
					for(int c=l;c>=b;c--){
						d[c]=0;
					}
					l=b-1;
					f=1;
					break;
				}
			}
			l++;
			d[l]=a[j];
		}
		for(int j=1;j<=l;j++){
			if(d[j]<=m){
				q[d[j]]++;
			}
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<q[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1

*/
