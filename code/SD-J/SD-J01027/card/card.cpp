#include<bits/stdc++.h>
#include<map>
using namespace std;
int c[500005];
int cnt=1,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//局数 
		for(int j=i;j<=n;j++){//遍历每局要打的牌 
			for(int k=cnt-1;k>0;k--){//遍历这张牌有没有打过 
				if(b[k]==a[j]){
					for(int u=k;u<cnt;u++){//如果有删除 
						b[u]=0;
						cnt--;
					}
				} 
			}
			b[cnt]=a[j];
			cnt++;
		}
		for(int j=1;j<cnt;j++){
			c[b[j]]++;
			b[j]=0;
		}//清空b + 将b中每一个数存入c中 
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	} 
	return 0;
}
