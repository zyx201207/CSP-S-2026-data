#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int b[N];
bool f[M];
int ans[M];
bool isA=1;
int lst[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])isA=0;
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==2){//20pts
		if(a[n]==1){
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2)tmp++;
			}
			cout<<n<<' '<<tmp;
		}else{
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)tmp++;
			}
			cout<<tmp<<' '<<n;
		}
		return 0;
	}
	if(isA){//16pts
		for(int i=1;i<m;i++){
			int k=lower_bound(a+1,a+1+n,i+1)-a;
			//lst[i]=k-1
			cout<<k-1<<' ';
		}
		cout<<n;
		return 0;
	}
	if(m==n){
		int poss[M]={};
		for(int i=1;i<=n;i++)poss[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<n-poss[i]+1<<' ';
		return 0;
	}
//	if(n<=500){//0~12pts
		for(int i=1;i<=n;i++){//O(n*(n*n+m))
			memset(f,0,sizeof f);
			memset(lst,255,sizeof lst);
			//start from the card i
			for(int j=i;j<=n;j++){
				if(f[a[j]]){
					for(int k=lst[a[j]]+1;k<j;k++){
						f[a[k]]=0;
						lst[a[k]]=-1;
					}
				}else f[a[j]]=1;
				lst[a[j]]=j;
			}
			for(int j=1;j<=m;j++){
				if(f[j]==1){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
//		return 0;
//	}
//	if(n<=5000){//大体正确,但细节暂时无法完善(即时间复杂度暂时无法压缩至O(n*n)),若考试结束时仍未完善完成,则注掉此段,用上一段的暴力
//		int dif[N]={};
//		for(int i=1;i<=n;i++){//O(n*(n*(n+2)))
//			memset(dif,0,sizeof dif);
////			memset(f,0,sizeof f);
//			memset(lst,0,sizeof lst);
//			for(int j=i;j<=n;j++){
//				if(lst[a[j]]){
//					for(int k=lst[a[j]]+1;k<j;k++)lst[a[k]]=0;//shorten the time used in this for() to O(1)
//					dif[j-1]--;
//					dif[lst[a[j]]-1]++;
//				}
//				ans[a[j]]++;
//				lst[a[j]]=j;
//			}
//			for(int j=n-1;j>=i;j--)dif[j]+=dif[j+1];
//			for(int j=i;j<=n;j++)ans[a[j]]+=dif[j];
//		}
//		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
//		return 0;
//	}
	return 0;
}