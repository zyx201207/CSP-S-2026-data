#include<bits/stdc++.h>
using namespace std;
int card[500100];
int tong[300100];
int jishu[500200];
int xiao[50100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w".stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>card[i];
	for(int i=1;i<=n;i++){
		jishu[500200]={0};
		xiao[50100]={0};
		int shu=0;
		for(int j=i;j<=n;j++){
			jishu[++shu]=card[j];
			xiao[card[j]]+=1;
			if(xiao[card[j]]==2){
				jishu[shu--]=0;
				while(jishu[shu]!=card[j]){
					jishu[shu]=0;
					shu--;
				}
				xiao[card[j]]=0;
			}
		}
		for(int s=1;s<=shu;s++)tong[jishu[s]]+=1;
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
} 
