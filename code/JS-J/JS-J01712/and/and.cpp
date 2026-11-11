#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
ll m,n,a[N],ans=0,num=-INF;
bool v[N];
void bfs(int x,int y){
	if(x>n||y>m){
       num=max(num,ans);
       return;
	}
	for(int i=x;i<=n;i++){
		if(!v[i]){
           v[i]=true;
           ans=ans&a[i];
           bfs(i+1,y+1);
           ans=ans|a[i];
           v[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bfs(1,0);
    cout<<num;
	return 0;
}