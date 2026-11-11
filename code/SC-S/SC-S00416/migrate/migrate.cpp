#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 5;

ll dy[N];
int lt[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		int ans = 0;
		ll d;
		cin>>n>>d;
		for(int i = 1;i <= n;++i)cin>>dy[i];
		int j = 1,i = 1;
		for(;i < n;){
			while(i < n && dy[i + 1] - dy[j] <= d)++i;
			lt[j] = i;
			j++;
		}
		for(int i = 1;i < j;++i){
			int cs = 1;
			while(i + cs * 2 - 1< j){
				int ni;
				for(int h = 1;h < cs;++h)ni = lt[i] + 1;
				int k = ni + 1;
				while(k < lt[ni] && k < j){
					if(lt[ni] - k + 1 == 2 && lt[k] != lt[ni])++ans;
					break;
				}
				++cs;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
