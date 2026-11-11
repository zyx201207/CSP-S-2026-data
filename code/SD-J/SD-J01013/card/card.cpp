#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
stack<int> s;
bool vis[N];
int a[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(vis[a[i]]){
			for(int j=0;j<i;j++){
				s.pop();
				vis[a[j]]=false;
			}
			s.push(a[i]);
			vis[a[i]]=true;
		}else{
			s.push(a[i]);
			vis[a[i]]=true;
		}
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<n;
	
	return 0;
}
