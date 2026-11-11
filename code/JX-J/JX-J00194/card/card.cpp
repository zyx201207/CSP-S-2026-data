#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        unordered_map<int,int>ump;
        stack<int>q;
        for(int j=i;j<=n;j++){
            int d=a[j];
            if(ump[d]==1){
                while(q.top()!=d){
                    ump[q.top()]=0;
                    q.pop();
                }
                ump[d]=0;
                q.pop();
            }
            ump[d]=1;
            q.push(d);
        }
        for(auto it=ump.begin();it!=ump.end();it++){
           if(it->second>0)cnt[it->first]++;
        }
	}
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
	return 0;
}
