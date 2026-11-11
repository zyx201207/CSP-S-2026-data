#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum,ans;
int cnt[1000001];
char dic[1000001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		cin>>dic[i];
		sum+=cnt[i];
	}
	int l;
	char lc;
	int i=1,j=n;
	for(int z=1;z<=n;z++){
		if(dic[i]!=dic[j]){
			if(cnt[i]>cnt[j]){
				cnt[i]-=cnt[j];
				ans+=cnt[j];
				j--;
			}
			else if(cnt[i]<cnt[j]){
				cnt[j]-=cnt[i];
				ans+=cnt[i];
				i++;
			}
			else{
				z++;
				ans+=cnt[i];
				j--;
				i++;
			}
		}
		else if(dic[i]==dic[j]){
			if(cnt[i]>cnt[j]){
				cnt[i]-=cnt[j];
				j--;
			}
			else if(cnt[i]<cnt[j]){
				cnt[j]-=cnt[i];
				i++;
			}
			else{
				z++;
				j--;
				i++;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

