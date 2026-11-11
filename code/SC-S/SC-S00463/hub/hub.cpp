#include<bits/stdc++.h>
using namespace std;
const int N=400;

int c,t;

int n,d,x[N],step[N],f[N],ans=0;

int v[N];



void bfs(int s){
	
	memset(v,0,sizeof(v));
	memset(step,0,sizeof(step));
	memset(f,0,sizeof(f));
	
	queue<int> q;
	q.push(s);
	v[s]=1;
	
	while(q.size()){
		
		int tp=q.front();
		q.pop();
		
		for(int j=tp+1;j<=n;j++){
			
			if(!v[j]){
				if(x[j]-x[tp]<=d){
					step[j]=step[tp]+1;
					v[j]=1;
					f[j]++;
					q.push(j);
				}
			}
			else{
				int ts=step[tp]+1;
				if(ts==step[j]){
					f[j]++;
				}
			}
			
		}
		
	}
	
}


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	
	while(t--){
		
		cin>>n>>d;
		
		ans=0;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}	
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bfs(i);
				if(f[j]==2) ans++;
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}