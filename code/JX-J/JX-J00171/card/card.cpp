#include<bits/stdc++.h>
using namespace std;
int tno[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tno[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>t(m);
		vector<int>jw(m);
		for(int j=i;j<=n;j++){
			t[tno[j]]++;
			if(t[tno[j]]==1){
				jw[tno[j]]=j;
			}
			if(t[tno[j]]>1){
				for(int x=jw[tno[j]];x<j;x++){
					t[tno[x]]--;
					jw[tno[x]]=0;
				}
				jw[tno[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]>0&&jw[j]>0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	}
