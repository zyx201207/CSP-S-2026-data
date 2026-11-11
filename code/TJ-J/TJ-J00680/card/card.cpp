#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010];
long long l[200010],ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[a[i]]=i;
	}
	stack<int>s;
	for(int i=n;i>=1;i--){
		if(i==1 and b[a[i]]==0) continue;
		if(l[a[i]]!=0){
			ans[a[i]]-=(l[a[i]]-i);
			l[a[i]]=0;
		}
		if(b[a[i]]==0){
			b[a[i]]=i;
			s.push(i);
		}
		else{
			while(true){
				int c=s.top();
				if(a[c]==a[i]) break;
				s.pop();
				l[a[c]]=i;
				b[a[c]]=0;
			}
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]-l[i]<<' ';
	}
	return 0;
}
