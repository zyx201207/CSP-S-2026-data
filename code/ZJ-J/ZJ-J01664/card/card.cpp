#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005]={0},desk[500005]={0},d=1;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long e=1;e<=n;e++){
		for(long long i=1;i<=d;i++){
			desk[i]=0;
		}
		d=1;
		for(long long i=e;i<=n;i++){
			bool flag=1;
			int s;
			for(long long j=1;j<=n;j++){
				if(desk[j]==a[i]){
					flag=0;
					s=j+1;
					break;
				}
			}
			if(flag){
				desk[d]=a[i];
				d++;
			}
			else{
				for(long long j=s;j<=d;j++)desk[j]=0;
				d=s;
			}
		}
		for(long long j=1;j<=d;j++){
			t[desk[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}