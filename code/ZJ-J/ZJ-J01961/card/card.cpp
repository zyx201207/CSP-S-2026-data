#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int a[500005],cnt[300005]={},last[300005]={};
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		last[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		int tar=i-1;
		while(++tar<n){
			st.push(a[tar]);
			tar=last[a[tar]];
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}
