#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '/n'
/*
直接按题意模拟
可以发现每次有重复的牌时最短O(1),最坏O(n),所以均摊下来大约是log(n)
所以总时间复杂度约为O(n^2logn+nm)
期望60 
*/
int a[500005],b[500005];
int id[500005];//每一轮中i上一次出现的位置 
int ans[500005];//1~m中每一个i有多少局游戏中出现 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p;
	for(int i=1;i<=n;i++){//考虑到第i轮游戏 
		memset(id,-1,sizeof(id));
		memset(b,0,sizeof(b));
		p=0;
		for(int j=i;j<=n;j++){
			if(id[a[j]]!=-1){
				for(int k=id[a[j]]+1;k<=p;k++){
					id[b[k]]=-1;
					b[k]=0;
				}
				p=id[a[j]];
			}else{
				p++;
				b[p]=a[j];
				id[a[j]]=p;
			}
//			for(int kkk=1;kkk<=p;kkk++){
//				cout<<b[kkk]<<" ";
//			}
//			cout<<endl;
//			for(int kkk=1;kkk<=n;kkk++){
//				cout<<"id["<<kkk<<"]="<<id[kkk]<<" ";
//			}
//			cout<<"p="<<p<<endl;
		}
//		for(int j=1;j<=p;j++){
//			cout<<b[j]<<" ";
//		}
//		cout<<endl<<endl;
		for(int j=1;j<=m;j++){//枚举1~m
			for(int k=1;k<=p;k++){
				if(b[k]==j){
					ans[j]++;
				}
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
