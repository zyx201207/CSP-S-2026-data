#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],p[N];
stack<int> st;
map<int,int> mp,mp1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=500){
		for(int i=1;i<=n;i++){
			mp1.clear(); 
			for(int j=i;j<=n;j++){
				if(mp1[a[j]]==0){
					st.push(a[j]);
					mp1[a[j]]=1;
				}else{
					while(st.top()!=a[j]){
						mp1[st.top()]=0;
						st.pop();
					}
				}
			}
			for(int j=1;j<=m;j++) mp[j]+=mp1[j];
		}
		for(int j=1;j<=m;j++) printf("%lld ",mp[j]);
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++) mp[a[i]]++;
		for(int i=1;i<=m;i++) mp[i]+=mp[i-1];
		for(int i=1;i<=m;i++) printf("%lld ",mp[i]);
	}
	else{
		if(m<=2){
			int c1=0,c2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) c1++;
				else c2++; 
			}
			if(a[n]==1){
				printf("%lld %lld\n",n,c2);
			}else{
				printf("%lld %lld\n",c1,n);
			}
		}
		else{
			for(int i=1;i<=n;i++) mp[a[i]]++;
			for(int i=1;i<=m;i++) mp[i]+=mp[i-1];
			for(int i=1;i<=m;i++) printf("%lld ",mp[i]);
		}
	}
	return 0;
}
