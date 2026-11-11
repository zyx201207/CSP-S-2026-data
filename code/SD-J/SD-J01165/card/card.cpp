#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
stack<int> s;
int cnt[300005];
int ans[300005];
int c;
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(!s.empty())s.pop();
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]!=0){
				while(s.top()!=a[j]){
					cnt[s.top()]--;
					s.pop();
				}
				cnt[s.top()]--;
				s.pop();
			}
			s.push(a[j]);
			cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]&&!f[j]){
				ans[j]++;
				f[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//会有人看到这行字吗:P 
