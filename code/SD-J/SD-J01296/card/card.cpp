#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,a[1000000],b[1000000],ans[1000000],temp;
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int x=0;x<n;x++){
		for(int i=0;i<999999;i++){
			b[i]=0;
		}
		for(int i=x;i<n;i++){
			if(b[a[i]]==0){
				q.push(a[i]);
				b[a[i]]++;
			}else{
				while(!q.empty()){
					temp=q.top();
					if(temp==a[i]){
						//cout<<"break\n";
						break;
					}
					q.pop();
					//cout<<"poped\n";
				}
			}
		}
		while(!q.empty()){
			temp=q.top();
			q.pop();
			//cout<<temp<<"\n";
			ans[temp]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
