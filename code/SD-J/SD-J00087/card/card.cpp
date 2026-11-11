#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,t[N],a[N],wcx,b[N],cnt,l[N],sum[N];//sum[i]表示答案最长后缀中i要被多少算(sum[i]=sum[b[i-1]]+t[i]...) 
bool vis[N];
void cl(){
	wcx=m;
	for(int i=n;i>=1;i--){
		if(wcx==0)break;
		if(vis[a[i]]==0){
			wcx--;
			b[++cnt]=a[i];
			vis[a[i]]=1;
		}
		else{
			for(int j=cnt;j>=1;j--){
				if(b[j]==a[i]){
					cnt=j;
					break;
				}
				vis[b[j]]=0;
				wcx++;
			}
		}
	}
	for(int i=cnt;i>=1;i--){
		sum[b[i]]=sum[b[i+1]]+t[b[i]];
	}
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	cl();
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
//	cout<<"\n";
//	for(int i=1;i<=cnt;i++)cout<<b[i]<<" ";
	return 0;
}
