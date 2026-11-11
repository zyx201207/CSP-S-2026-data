#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int ins[N],cnt[M],a[N],lst[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,A=1; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lst[a[i]]=max(lst[a[i]],i);
		if(i>=2&&a[i]<a[i-1]) A=0;
	}
	if(A){
		for(int i=1;i<=m;i++) cout<<lst[i]<<" ";
		cout<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(ins,0,sizeof(ins));
		for(int j=i;j<=n;j++){
			if(ins[a[j]]){ while(!st.empty()&&st.top()!=a[j]) ins[st.top()]=0,st.pop(); }
			else{ ins[a[j]]=1,st.push(a[j]); }
		}
		while(!st.empty()){ cnt[st.top()]++,st.pop(); }
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	printf("\n");
	return 0;
}
