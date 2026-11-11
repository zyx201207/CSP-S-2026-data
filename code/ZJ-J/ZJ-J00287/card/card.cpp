#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		deque<int>q;
		int in[m+1];
		memset(in,0,sizeof(in));
		for(int j=i;j<=n;j++){
			if(in[a[j]]!=0){
				while(!q.empty()&&q.back()!=in[a[j]]){
					if(in[a[q.back()]]==q.back()) in[a[q.back()]]=0;
					q.pop_back();
				}
			}else{
				q.push_back(j);
				in[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(in[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}