#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long n,m,a[N],t[M],p[M],cnt,tt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) tt[j]=-1;
		cnt=0;
		for(int j=i;j<=n;j++){
			if(tt[a[j]]==-1){
				p[++cnt]=a[j];
				tt[a[j]]=cnt;
			}
			else{
				cnt=tt[a[j]];
				for(int k=cnt+1;k<=m;k++){
					tt[p[k]]=-1;
					p[k]=0;
				}
			}
		}
		for(int j=1;j<=cnt;j++)
			t[p[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
