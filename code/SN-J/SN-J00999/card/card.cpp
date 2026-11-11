//WA= 48 #1234 AC
#include<bits/stdc++.h>
#define fri(x,y) for(int i = x;i <= y;i++)
#define frj(x,y) for(int j = x;j <= y;j++)
#define MAXN 500000 + 10
#define MAXM 300000 + 10
#define lihaoming 0
#define ll long long
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int ls[MAXN];
int ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	fri(1,n){
		cin>>a[i];
	}
	for(int k = 1;k <= n;k++){
		fri(k,n){
			if(b[a[i]] == 0){}
			else{
				int i2 = i,i3 = b[a[i]];
				while(i2 > i3){
					i2--;
					b[a[i2]] = 0;
					ls[i2] = 0;
				}
			}
			b[a[i]] = i;
			ls[i] = a[i];
		}
//		cout<<"k="<<k<<endl;
//		fri(1,n){
//			cout<<ls[i]<<" ";
//		}
//		cout<<endl;
		fri(1,n){
			if(!ls[i])continue; 
			ans[ls[i]]++;
			ls[i] = 0;
			b[i] = 0;
		}
	}
	fri(1,m){
		cout<<ans[i]<<" ";
	}
	return 0;
}

// 空悲切 qwq 
//WA- 0
//#include<bits/stdc++.h>
//#define fri(x,y) for(int i = x;i <= y;i++)
//#define frj(x,y) for(int j = x;j <= y;j++)
//#define MAXN 500000 + 10
//#define MAXM 300000 + 10
//#define lihaoming 0
//#define ll long long
//using namespace std;
//int n,m;
//int a[MAXN];
//int b[MAXN];
//int cnt[MAXN];// 保存要扣掉的数 
//int ans[MAXN];
//int main(){
//	//freopen("card.in","r",stdin);
//	//freopen("card.out","w",stdout);
//	cin>>n>>m;
//	fri(1,n){
//		cin>>a[i];
//	}
//	int k = 0;// 目前剩的数 
//	fri(1,n){
//		k++;
//		if(b[a[i]] == 0){
//			b[a[i]] = k;
//			ans[a[i]] = i;
//		}
//		else{
//			int i2 = b[a[i]];
//			while(k > i2){
//				k--;
//				b[a[k]] = 0;
//				cnt[a[k]] += k - i2;
//			}
//			b[a[i]] = k;
//			ans[a[i]] = i;
//		}
//		cout<<"导入a["<<i<<"]("<<a[i]<<")后，";
//		cout<<"目前还有"<<k<<"个数\n";
//		cout<<"b  ={ ";
//		frj(1,m) cout<<b[j]<<" ";
//		cout<<"}\n";
//		cout<<"cnt={ ";
//		frj(1,m) cout<<cnt[j]<<" ";
//		cout<<"}\n";
//		cout<<"ans={ ";
//		frj(1,m) cout<<ans[j]<<" ";
//		cout<<"}\n";
//	}
//	fri(1,m){
//		cout<<ans[i] - cnt[i]<<" ";
//	}
//	return 0;
//}
/*

text
4 3 1 2 1 3
out:3 1 4
10 3 3 1 2 1 3 2 3 1 2 1
out:10 3 3
*/
/*

mind
1.使用 b 数组保存 a[i] 是否在牌堆内，其中 b[a[i]] 表示位置 
若在，i2 = i，一直将 cnt[a[i]]--,i--
直到 i == b[a[i2]] (i2 表变化前 a[i]) 
若不在，继续遍历，cnt[a[i]]++，b[a[i]] = i 
可以得知，遍历一次 n 张牌的时间为 2n 
总结时 fri(1,n){ans[a[i]]++} 
若以此进行遍历，复杂度为 O(3n) 
枚举 n 种答案，总复杂度为 O(3n^2) 48 pts
2.在1的基础上，假设使用 frj(k,n) (1<=k<=n) 枚举，
每个 a[i]的权重为 i 
观察样例 1 发现，ans[3] = 4 ，于是猜测ans[]与i有关 
于是，在遍历 fri(1,n) 时，直接对 ans 进行更改 
所以对于循环内的 i ，开始时直接 ans[a[i]] = i 
在 1 的基础上，发现 b[i] 赋值时不为空， 
回溯时直接 ans[i] -= i - b[a[i2]] 
测试样例 1： 
k = 1:
put(1),a[]=1
b[]={1,0,0,0}ans[]={0->1,0,0,0}
put(2),a[]=1,2
b[]={1,2,0,0}ans[]={1,0->2,0,0}
put(1),a[]=1
b[]={1,2->0,0,0}ans[]={1->3,2-1=1,0,0}
put(4),a[]=1,3
b[]={1,0,2,0}ans[]={3,1,0->4,0}
100- pts
*/
