#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[500005],ans[500005],stk[500005],last[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(last,0,sizeof(last));
		len=0;
		for(int j=i;j<=n;j++){
			if(last[a[j]]){
				while(len>last[a[j]]){
					if(len!=last[a[j]])last[stk[len]]=0;
					len--;
				}
			}
			else{
				stk[++len]=a[j];
				last[a[j]]=len;
			}
		}
		for(int j=1;j<=len;j++)
			ans[stk[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
} 
