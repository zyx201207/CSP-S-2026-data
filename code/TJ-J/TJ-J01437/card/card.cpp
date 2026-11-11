#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int box[300005];
bool used[300005];
void j(int m){
	memset(used,false,sizeof(used));
	stack<int>s;
	for(int i=m;i<=n;i++){
		if(used[a[i]]){
		    while(s.top()==a[i]){
		    	used[s.top()]=false;
		    	s.pop();
			}
		}else{
		    used[a[i]]=true;
		    s.push(a[i]);
		}
	}
	while(s.size()){
		box[s.top()]++;
		s.pop();
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--) j(i);
	for(int i=1;i<=m;i++) printf("%d ",box[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
