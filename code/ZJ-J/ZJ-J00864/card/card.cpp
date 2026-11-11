#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],last[N];
long long val[N],f[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],val[i]=1;
    for(int i=1;i<=n;i++)last[a[i]]=i;
    for(int i=1;i<=n;i++)
	   val[last[a[i]]+1]+=val[i];
    for(int i=n;i>=1;i--){
    	if(last[a[i]]==i)continue;
    	f[i]+=val[i],f[last[a[i]]]-=val[i];
	}
	for(int i=1;i<=n;i++)f[i]+=f[i-1];
	for(int i=1;i<=m;i++)cout<<last[i]-f[last[i]]<<" ";
	return 0;
}