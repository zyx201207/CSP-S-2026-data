/*
记录二进制第i位为1的数字有哪些
把最大的纪录下来，然后再从最大的里面继续这个操作
直到fi<m
这个过程中位运算记录结果即可 
n log n
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
vector <int> f[N];
vector <int > f2;
int maxi=32,max_tmp=0;
int n,m;
void fix(int x){
	int xx=x;
	int cnt=0;
	while(x>0){
		cnt++;
		if(x%2) {
			f[cnt].push_back(xx);
			if(f[cnt].size()>=m  && cnt<maxi) {//再要求内
				max_tmp=max(cnt,max_tmp);
			}
		}
		x/=2;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		fix(a[i]);
	}
	int ans=0;
	while(1){
		f2.clear();
		if(max_tmp==0) {
			cout<<ans;
			return 0;
		}
		maxi=max_tmp;
		max_tmp=0;
		for(int j=0;j<f[maxi].size();++j) {
			f2.push_back(f[maxi][j]);
		}
		int tmp_n=f[maxi].size();
		ans+=(1<<(maxi-1));
		for(int i=1;i<=32;++i) f[i].clear();
		for(int i=0;i<tmp_n;++i) fix(f2[i]);
	}
	return 0;
	
}
/*
4 2
3 15 12 12

*/
