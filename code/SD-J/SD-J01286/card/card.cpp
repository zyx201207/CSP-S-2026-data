#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h,ch,b[300001],s[300001],a[500001];
int iff(){
	for(int i=1;i<=n;i++)if(a[i]<a[i-1])return 0;
	return 1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ch=iff();
	for(int q=1;q<=n;q++){
		memset(b,0,sizeof b);
		for(int i=q;i<=n;i++){
			int t=-1;
			if(ch){
				t=lower_bound(b+1,b+1+h,a[i])-b;
				if(t<0||t>300001||b[t]!=a[i])t=-1;
			}
			else{
				for(int k=1;k<=h;k++){
					if(b[k]==a[i]){
						t=k;
						break;
					}
				}
			}
			if(t!=-1)h=t;
			else b[++h]=a[i];
		}
		for(int i=1;i<=h;i++)s[b[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
