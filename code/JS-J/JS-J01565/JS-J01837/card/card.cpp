#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500005];
int ans[300005];
bool flag[300005];//24pts
int st[500005],top=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(flag[a[j]]==0){
			top++;
			st[top]=a[j];
			flag[a[j]]=1;
		}else{
			while(flag[a[j]]==1&&top>=0){
				int t=st[top];
				flag[t]=0;
				top--;
			}
			top++;
			st[top]=a[j];
			flag[a[j]]=1;
		}
	}
	while(top>=0){
		int t=st[top];
		ans[t]++;
		flag[t]=0;
		top--;
	}
	top=-1;
}
for(int i=1;i<=m;i++){
	cout<<ans[i]<<" ";
}
	return 0;
}//CSP 2026 RP++
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
