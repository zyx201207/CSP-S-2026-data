#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],l[300100],ans[300100];
bool r[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			r[i]=false;
		}
		deque<int> card;
		for(int j=i;j<=n;j++){
			if(r[a[j]]==0){
				r[a[j]]=true;
				card.push_back(a[j]);
			}
			else{
				while(true){
					if(card.back()==a[j]){
						break;
					}
					else{
						r[card.back()]=false;
						card.pop_back();
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(r[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}