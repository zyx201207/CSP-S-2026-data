#include<bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;
const int N=5e5,M=3e5+5;
int n,m;
int ans[M];
struct node{
	int a;
	int id;
}s[N];
node sum[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		s[i].id=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum[s[j].a].a++;
			if(sum[s[j].a].a>=2&&sum[s[j].a].id!=0){
				for(int k=sum[s[j].a].id;k<=j-1;k++){
					sum[s[k].a].a=0;
				}
			}
			sum[s[j].a].a++;
			sum[s[j].a].id=j;
		}
		for(int j=1;j<=m;j++){
			if(sum[j].a>0){
				ans[j]++;
			}
			sum[j].a=0;
			sum[j].id=0;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}
