#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[500010];
int ans[300010]; 
int b[500010],len;//b是在桌面上的牌 
int id[300010];//b数组中，i号数字在b[id]的位置上，如果没有i,b[i]=0 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(id[a[j]]==0){
				b[++len]=a[j];
				id[a[j]]=len;
			}
			else{
				for(int k=id[a[j]]+1;k<=len;k++){
					id[b[k]]=0;
				}
				len=id[a[j]];
			}
		}
		for(int j=1;j<=len;j++){
			ans[b[j]]++;
			id[b[j]]=0;
		}
		len=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
//Trick||Treat!
