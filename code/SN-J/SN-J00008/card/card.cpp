#include<bits/stdc++.h>
using namespace std;
int n,m;
int l[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		string play="";
		for(int j=i;j<=n;j++){
			if(play.find(l[j]+'0')){
				play="";
			}
			play+=l[j]+'0';
		}
		cout<<play<<endl;
		for(int i=0;i<play.size();i++){
			ans[play[i]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
