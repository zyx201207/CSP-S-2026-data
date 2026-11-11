#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=5010;
int a[N],ans[N]={0};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
/*啊哈哈哈哈哈哈哈神秘的主程序*/
	for(int i=1;i<=n;++i){
		int t[5010];
		int cnt=0;
		for(int j=i;j<=n;++j){
			bool flag=false;
			int k=a[j],kx=0;
			for(int p=1;p<=cnt;++p){
				if(t[p]==k)flag=true,kx=p;
			}
/*气哭了为啥一直RE*/ 
			if(flag){
				int all=cnt;
				for(int p=kx+1;p<=all;++p)t[p]=0,cnt--;
			}else{
				cnt=cnt+1;
				t[cnt]=k;//RE			
			}
		}
		for(int j=1;i<=cnt;++j){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}
