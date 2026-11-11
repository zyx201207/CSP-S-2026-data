#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define fi first
#define se second
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,a[500005],x;
	cin>>n>>x;
	int sum[500005];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>tmp;
		for(int j=i;j<=n;j++){
			int pos=-1;
			for(int k=0;k<tmp.size();k++){
				if(tmp[k]==a[j]){
					pos=i;
					break;
				}
			}
			if(pos==-1){
				tmp.push_back(a[j]);
			}
			else{
				vector<int>tmp2;
				for(int k=0;k<tmp.size();k++){
					if(tmp[k]!=a[j])tmp2.push_back(tmp[k]);
					else break;
				}
				tmp=tmp2;
				tmp.push_back(a[j]);
			}
		}
		for(int i:tmp)sum[i]++;
	}
	for(int i=1;i<=x;i++)cout<<sum[i]<<' ';
	return 0;
} 
