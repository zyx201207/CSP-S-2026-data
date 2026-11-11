#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int a[N],me[N],op[N],qq[N],ans_j[N],ans[N];
void solve(){
    int  n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
    cin>>a[i];	
    }
    for (int i=0;i<n;i++)ans[i]=0;
    for (int L=0;L<n;L++){
    for (int i=0;i<=n;i++)qq[i]=1,ans_j[i]=0;
    for (int i=1;i<=m;i++)op[i]=-1;
    for (int i=0;i<=n;i++) me[i]=-1;
	for (int i=L;i<n;i++){
	if (op[a[i]]!=-1){
	me[op[a[i]]]=i;	
	}
    op[a[i]]=i;	
	}
	for (int i=L;i<n;i++){
	if (me[i]!=-1&&qq[i]){
	for (int j=i;j<me[i];j++)qq[j]=0;	
	}
	}
	for (int i=L;i<n;i++){
	if (qq[i]==1)ans_j[a[i]]=1;
	}
	for (int i=1;i<=m;i++){
	ans[i]+=ans_j[i];	
	}	
	}
	for (int i=1;i<=m;i++){
	cout<<ans[i]<<" ";	
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
//	cin>>T;
	while (T--)solve();
	return 0;
}

