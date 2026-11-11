
#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m;
int pa[500010],ans[500010];
bool find(int a){
	int zh[q.size()],cnt=0;
	for(int i=0;i<int(q.size());i++){
		if(q.front()==a){
			for(int j=cnt;j>=0;j--){
				q.push(zh[j]);
			}
			return 1;
		}
		else{
			zh[cnt++]=q.front();
			q.pop();
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>pa[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(i==j) continue;
            if(find(pa[i])){
                q.push(pa[i]);
            }
            else{
                while(q.size()) q.pop();
                q.push(pa[i]);
            }
        }
        while(q.size()){
            int a=q.front();q.pop();
            ans[a]++;
        }   
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}

