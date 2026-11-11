#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int ans[3000005];
int a[3000005];
int v[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool sss=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])sss=0;
	}
	if(sss){
		int sum=0;
		int s=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				sum+=s;
				cout<<sum<<' ';
				s=0;
			}
			s++;
		}
		if(a[n]!=a[n-1]){
				sum+=s;
				cout<<sum<<' ';
				s=0;
			}
		return 0;
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		memset(v,0,sizeof(v));
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				s.push(a[j]);
//				cout<<"push"<<endl;
				v[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					v[s.top()]=0;
					s.pop();
//					cout<<"pop"<<endl;
					
				}
				s.push(a[j]);
//				cout<<"push"<<endl;
				v[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(v[j]==1)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
//36p 11:55

//100+100+75+36