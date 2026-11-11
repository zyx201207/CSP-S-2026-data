#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[10000010],n,m,ans[10000010];
bool fl[10000010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	for(int k=1; k<=n; k++) {
		for(int i=k; i<=n; i++) {
			fl[i]=true;
			bool f=false;
			for(int j=k; j<i; j++) {
				if(arr[j]==arr[i]&&!f&&fl[j]) {
					f=true;
				}
				if(f&&fl[j]) {
					ans[arr[j]]--;
					fl[j]=false;
				}
			}
			ans[arr[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
读取到数转为二进制存入数组并在val中标记第i位为1的数中有一个的下标为i
因为1000>111所以从最大位开始跑如果当前位为1的数的个数大于等于m那这一位就可以被计入答案
当某一位被选好时有可能出现大于m个数满足条件那么就在这几个数中再找最大答案
*/
