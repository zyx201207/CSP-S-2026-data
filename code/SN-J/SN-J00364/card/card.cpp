#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int arr[500005];
vector<int> tg[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		tg[arr[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		if(arr[n]==i){
			cout<<n<<" ";
			continue;
		}
		ans=tg[i].size();
		for(int j=0;j<ans-1;j++){
			bool bl=true;
			for(int k=tg[i][j]+1;k<tg[i][j+1];k++){
				if(tg[arr[k]].back()>tg[i][j+1]){
					bl=false;
					break;
				}
			}
			if(bl) ans+=tg[i][j+1]-tg[i][j]-1;
		}
		cout<<ans<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
