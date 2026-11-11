#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[35];
int ans[200005];
vector<int> ve[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=a[i],z=0;
		while(cnt){
			z++;
			if(cnt%2==1){
				ve[z].push_back(i);
				sum[z]++;
			}
			cnt/=2;
		}
	}
	bool f=0;
	int  x=1;
	for(int i=32;i>=1;i--){
		if(sum[i]>=m){
			if(f==0){
				f=1;
				int cnt=0;
				for(auto j:ve[i]){
					ans[j]=1;
					cnt++;
				}
				if(cnt==m){
					x++;
					break;
				}
				x++;
			}else{
				int cnt=0;
				for(auto j:ve[i]){
					if(ans[j]==x-1){
						cnt++;
					}
				}
				
				if(cnt>=m){
					for(auto j:ve[i]){
						if(ans[j]==x-1){
							ans[j]=x;
						}
					}
					if(cnt==m){
						x++;
						break;
					}
					x++;
				}
			}
		}
	}
	bool fl=0;
	int ans1=0;
	for(int i=1;i<=n;i++){
		if(ans[i]==x-1){
			if(fl==0){
				fl=1;
				ans1=a[i];
			}else{
				ans1&=a[i];
			}
		}
	}
	cout<<ans1;
	return 0;
}
