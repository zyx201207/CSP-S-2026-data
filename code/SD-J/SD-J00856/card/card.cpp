#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> kkksc03;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],s[M],b[N],vis[N],top=0;
int main(){
//	freopen("card1.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=1;j<=m;j++)vis[j]=0;
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					b[++top]=a[j];
					vis[a[j]]=top;
				}else{
					while(b[top]!=a[j]){
						vis[b[top]]=0;
						top--;
					}
				}
			}
			for(int k=1;k<=top;k++){
				s[b[k]]++;
			}
		}
		for(int i=1;i<=m;i++)printf("%d ",s[i]);
	}else{
		for(int i=1;i<=n;i++){
			s[a[i]]=i;
		}
		s[a[0]]=1e9;
		for(int i=1;i<=m;i++){
			int k;
			for(k=s[i]-1;s[a[k]]>s[i]&&k>=0;k--);
			b[i]=k;
		}
		for(int i=1;i<=m;i++){
			printf("%d ",s[i]-b[i]);
		}
	}
	return 0;
}
//求CCF不要在下午出子任务捆绑喵！ 
/*
luogu:1143716关注谢谢喵(广交鱼航员) 

游记
8:30 输入密码Trick||Treat!，解锁了文件
8:50 弄完了“小”模拟第一题，感觉自己好弱…… 
9:07 第二题打好了
9:31 第三题用了一个O(30n)的时间复杂度弄好了！ 
*/
