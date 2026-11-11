#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010,M=300010;
struct node{
	int a,num;
}x[N];
int n,m,a[N],ans[M];
bitset<M>f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tt=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=x[tt].a)x[++tt]={a[i],1};
		else ++x[tt].num;
	}
	if(m==2){
		if(n&1){
			ans[a[1]]=n;
			ans[x[tt-1].a]=x[tt-1].num;
		}else{
			for(int i=0;i<tt;i++){
				ans[x[i].a]+=x[i].num;
				if((i&1)==0)ans[x[i+1].a]+=x[i].num;
			}
		}
		cout<<ans[1]<<' '<<ans[2]<<'\n';
		return 0;
	}
	n=tt;
	if(n==m){
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=x[i].num;
			cout<<sum<<' ';
		}
		return 0;
	}
//	for(int i=1;i<=n;i++)cout<<x[i].a<<' ';
//	cout<<'\n'; 
	for(int i=1;i<=n;i++){
		stack<int>st;
		for(int j=i;j<=n;j++){
			while(f[x[j].a]){
				f[st.top()]=0;
				st.pop();
			}
			st.push(x[j].a);
			f[x[j].a]=1;
		}
		for(int j=1;j<=m;j++)if(f[j])ans[j]+=x[i].num;
		f.reset();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
