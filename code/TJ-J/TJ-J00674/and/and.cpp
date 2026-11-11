#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long k[32];
long long a[MAXN];
long long cnt[32][MAXN];
vector<int> s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	k[0]=1;
	for(int i=1;i<=29;i++)
		k[i]=k[i-1]*2;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=29;j>=0;j--)
			if(a[i]>=k[j]){
				cnt[j][0]++;
				cnt[j][cnt[j][0]]=i;
				a[i]-=k[j];
			}
	long long ans;
	int f;
	for(int i=29;i>=0;i--)
		if(cnt[i][0]>=m){
			f=i;
			for(int j=1;j<=cnt[i][0];j++)
				s.push_back(cnt[i][j]);
			break;
		}
	ans=s[s.size()-1];
	for(int i=s.size()-1;i>=s.size()-m;i--)
		ans=ans ^s[i];
	cout<<ans;
	return 0;
}
