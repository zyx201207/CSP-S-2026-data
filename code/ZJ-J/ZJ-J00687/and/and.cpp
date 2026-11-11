#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,m,x,ans;
vector<int>pre;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&x),pre.push_back(x);
	vector<int>a;
	for(int k=30;k>=0;k--){
		for(int i:pre){
			if(i&(1<<k)){
				a.push_back(i);
			}
		}
		if(a.size()>=m){
			ans|=1<<k,pre=a;
		}
		a.clear();
	}
	printf("%d",ans);
	return 0;
}
