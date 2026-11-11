#include<bits/stdc++.h>
#define inf 300005
using namespace std;
int n,m;
vector<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//  no"//"!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector<int>ans(m+5);
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}
	for(int i=1;i<=n;i++){
		vector<int>work=a,len(m+5);
		for(int j=i;j<=n;j++){
			len[work[j]]++;
		}
		for(int j=i,k;j<=work.size();j++){
			k=work[j];
			if(len[k]>1){
				for(int now=j;now<work.size();){
					len[*work.end()]--;
					work.erase(work.end()); 
				}
			}
			work.push_back(k);
		}
		for(int j=0;j<=m;j++){
			if(len[j])ans[len[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
