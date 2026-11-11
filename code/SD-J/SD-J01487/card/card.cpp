#include<bits/stdc++.h>
using namespace std;
int n,t[200005],a[200005],flag[200005],m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int XXX=0;XXX<n;XXX++){
		memset(flag,0,sizeof flag);
		stack<int> s;
		for(int i=XXX+1;i<=n;i++){
			if(flag[a[i]]){
				while(s.top()!=a[i]){
					flag[s.top()]=0;
					s.pop();
				}
			}
			else s.push(a[i]);
			flag[a[i]]=1;
		}
		for(int i=1;i<=m;i++) t[i]+=flag[i];
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
