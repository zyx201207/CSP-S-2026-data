#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],t[N],ans[N],st[N],top;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(top&&a[st[top]]!=a[j]){
					t[a[st[top]]]=0;
					top--;
				}
			}
			else{
				st[++top]=j;
				t[a[j]]=1;
			}
		}
		while(top>0){
			ans[a[st[top]]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

