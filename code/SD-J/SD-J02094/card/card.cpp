#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const int N = 1e6+10;
int n,m,a[N],b[N],c[N],bg[N],la[N];
ll ans[N],cnt,cntt; 
bool flag;
set<int> se;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		se.insert(a[i]);
		if(a[i]==1) cnt++;
		else cntt++;
	}
	if(se.size()==1){ cout<<n; return 0;}
	if(se.size()==2){
		if(a[n]==1) cout<<n<<" "<<cntt;
		else cout<<cnt<<" "<<n;
		return 0;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){ flag=1; break;}
	}
	if(!flag){
		for(int i=1;i<=n;i++) ans[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			int res=i-1;
			for(int j=i;j<=n;j++){
				for(int k=res;k>=i;k--){
					if(c[k]==a[j]){res=k-1; break;}
				}
				c[++res]=a[j];
			}
			for(int j=i;j<=res;j++) ans[c[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
