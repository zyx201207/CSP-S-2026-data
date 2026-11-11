#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"
#define ll long long
ll n,m,a[500005],q[500005],top=0,cnt,flag,flag2,t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		top=0;
		cnt=flag=0;
		for(int j=i;j<=n;j++){
			for(int k=top;k>=1;k--){
				if(q[k]==a[j]){
					top=k-1;
				}
			}q[++top]=a[j];
		}for(int i=1;i<=top;i++){t[q[i]]++;}
	}for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
}
