#include<bits/stdc++.h>
using namespace std;

//È¥×¢ÊÍ

#define endl '\n'

long long a[500005];
long long ans[500005];
int n,m;



int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	for(int i=1;i<=n;i++){
		stack<int>s;
		int vis[500005]={0};		
		for(int j=i;j<=n;j++){
			//cout<<j<<" "<<a[j]<<endl;
			//for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
			//cout<<endl<<"*";
			//for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
			//cout<<endl;
			if(vis[a[j]]==1){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}
			else {
				s.push(a[j]);
				vis[a[j]]=1;
			}
			
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
/*


4 3
1 2 1 3

3 1 4




10 3
3 1 2 1 3 2 3 1 2 1



10 3 3

*/	
	
	
	
	
	
	
	return 0;
} 

//freopen("ant.in","r",sdin);cc
//freopen("&.ans","w",stdot);
//freopen("114514.int","r",pstdin);
//freopen("cin>>n.out","w",gunmu);
//freopen("f.114514","r",stdin);
//freopen("travl.ut","w",stdout);
//114514#include<bits\stdc++.h>#include<bits\stdc++.h>#include<bits\stdc++.h>F

//my luogu id is clyzsmx2024,guanzhu me;
