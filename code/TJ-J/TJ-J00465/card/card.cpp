#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],tong[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		vector<int>card;
		for(int j=i;j<=n;j++){
//			for(auto x:card)cout<<x<<" ";
//			cout<<"\n"; 
			for(int k=0;k<card.size();k++){
				if(a[j]==card[k]){
					int t=card.size();
//					cout<<"!"<<k<<"|"<<card.size()<<"!\n";
					for(int l=k;l<t;l++)card.pop_back();
					break;
				}
			}
			card.push_back(a[j]);
//			for(auto x:card)cout<<x<<" ";
//			cout<<"\n\n"; 
		}
		for(int k=0;k<card.size();k++)tong[card[k]]=1;
		for(int j=1;j<=m;j++)ans[j]+=tong[j];
//		cout<<"\n\n\n";
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
