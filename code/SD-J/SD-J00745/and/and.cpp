#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int b[36][200005];
queue<int> q;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	q.push(0);
	for(int i=1; i<=n; i++) {
		int a;
		cin>>a;
		int j=1;
		while(a) {
			if(a%2) {
				b[j][0]++;
				b[j][i]=1;
			}
			j++;
			a/=2;
		}
		q.push(i);
	}
	for(int i=35; i>=1; i--) {
		if(b[i][0]>=m) {
			for(int j=1; j<=35; j++) {
				b[j][0]=0;
			}
			q.push(q.front());
			q.pop();
			while((!q.empty())&&q.front()) {
				if(b[i][q.front()]) {
					for(int k=1; k<=35; k++) {
						b[k][0]+=b[k][q.front()];
					}
					q.push(q.front());
					q.pop();
				} else {
					q.pop();
				}
			}
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;

	return 0;
}
