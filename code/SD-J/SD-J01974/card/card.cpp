#include<bits/stdc++.h>
using namespace std;
int a[500050];
int fl[500050];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int xx=0,yy=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(fl[a[i]]==0){
			fl[a[i]]=i;
		}
		else{
			xx=fl[a[i]];
			yy=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(fl[i]>=xx){
			cout<<fl[i]<<endl;
		}
		else if(fl[i]==0){
			cout<<0<<endl;
		}
		else{
			cout<<fl[i]-yy<<endl;;
		}
	}
	return 0;
}
