#include <bits/stdc++.h>
using namespace std;

int n,m;
int ca[500005];
int loc_[500005];//lianbiao zhi zhen
int loc[300005];//first=the last location the number appear
int allowed[500005];//the times that this number could be used;
int ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> ca[i];
		if(loc[ca[i]]){
			loc_[loc[ca[i]]]=i;
		}
		loc[ca[i]]=i;
	}

	for(int i=1;i<=n;i++){

		ans[ca[i]]+=i;
		allowed[i]+=i;
		if(loc_[i]){
			for(int l=i+1;l<loc_[i];l++){
				ans[ca[l]]-=allowed[i];
				allowed[l]-=allowed[i];
			}
			ans[ca[i]]-=allowed[i];
			allowed[i]=0;
		}
	}
	//for(int i=1;i<=n;i++)cout << allowed[i] << ' ';cout << endl;
	for(int i=1;i<=m;i++)cout << ans[i] << ' ';
	return 0;
}