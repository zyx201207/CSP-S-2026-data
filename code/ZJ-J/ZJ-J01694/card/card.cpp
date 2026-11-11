#include<iostream>
#include<map>
#include<set>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+5;
int vis[MAX];
int add[MAX];
int a[MAX];
ll card[MAX];
map<ll,int> mp;
set<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		s.clear();
		for(int j=i-1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=1;j<=m;j++){
			a[j]=0;
			add[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(s.find(card[j])!=s.end()){
				vis[a[card[j]]]=1;
				vis[j]=-1;
			}
			else{
				s.insert(card[j]);
				a[card[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			vis[j]=vis[j]+vis[j-1];
			if(vis[j]==0) add[card[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(add[j]) mp[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
