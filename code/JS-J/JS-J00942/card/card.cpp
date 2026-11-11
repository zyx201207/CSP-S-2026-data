#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],s[300002];
bool b[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				q.push(a[j]);
				//cout<<a[j]<<" ? ";
				b[a[j]]=1;
			}else{
				while(!q.empty()&&q.top()!=a[j]){
					//cout<<q.top()<<"!!!"<<a[j]<<"no...";
					b[q.top()]=0;
					q.pop();
				}
				
			}
		}
		//cout<<endl;
		while(!q.empty()){
			s[q.top()]++;
			//cout<<q.top()<<" ";
			q.pop();
		}//cout<<endl<<endl;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
