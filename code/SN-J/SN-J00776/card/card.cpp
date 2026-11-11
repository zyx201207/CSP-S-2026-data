//姓名:张泽凯,考号:SN-J00776,学校:西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10003],tj[10003]={};
	deque<int>c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int game=1;game<=n;game++){
		bool b[10003]={};
		for(int i=game;i<=n;i++){
		if(b[a[i]]==0){
			c.push_front(a[i]);
			b[a[i]]=1;
		}
		else{
			while(1){
				if(c.front()==a[i]){
					c.pop_front();
					break;
				}
				c.pop_front();
			}
			c.push_front(a[i]);
		}
		}
		while(!c.empty()){
			++tj[c.front()];
			c.pop_front();
		}
	}
	for(int i=1;i<=m;i++)cout<<tj[i]<<" ";
	return 0;
}
