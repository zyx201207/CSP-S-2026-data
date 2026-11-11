#include<bits/stdc++.h>
using namespace std;
int t,n,d,a[2000009];
long long ans;
bool pd(int u,int v){
	queue<int> q;
	int h=0;
	q.push(u);
	while(q.size()){
		int uu=q.front();
		q.pop();
//		cout<<uu<<" "<<h<<" "<<q.size()<<"   *\n";
		if(a[v]-a[uu]<=d)h++;
		else{
			for(int i=v-1;i>uu;i--){
//				cout<<i<<" ";
				if(a[i]-a[uu]<=d)q.push(i);
			}
		}
	}//cout<<h<<" "<<u<<" "<<v<<"  *\n";
	if(h==2)return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int z=i+1;z<=n;z++){
				ans+=pd(i,z);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2 
-4 -3 -2 -1 3 6
*/