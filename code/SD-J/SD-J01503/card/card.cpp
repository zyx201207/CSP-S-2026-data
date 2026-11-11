#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,M=1e3+10;
int n,m;
int a[N];
bool vis[N];
int sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		//cerr<<"11111\n";
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				s.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				//cerr<<i<<" "<<j<<" 11111\n";
				while(s.empty()==0){
					if(s.top()!=a[j]){
						vis[s.top()]=0;
						//cerr<<s.top()<<"\n";
						s.pop();
					}
					else{
						break;
					}
				}
				vis[s.top()]=0;
				s.pop();
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(s.empty()==0){
			sum[s.top()]++;
			vis[s.top()]=0;
			//cerr<<i<<" "<<s.top()<<"\n";
			s.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
