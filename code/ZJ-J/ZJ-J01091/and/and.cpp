#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
int a[N],p[N];
ll sum[N],res;
queue<int> q,s;
void init(){
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;init();
	for(int i=1;i<=n;i++) cin>>a[i],q.push(a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=30;j++)
			if(a[i]&p[j]) sum[j]++;
	int cnt=30;
	for(int i=30;i>=0;i--){
		if(sum[i]>=m) res+=p[i];
		else continue;
		int ma=0;
		for(int j=0;j<=i;j++) sum[j]=0;
		if(cnt%2==0){
			cnt--;
			while(!q.empty()){
				int x=q.front();q.pop();
				if(x&p[i]){
					for(int j=i-1;j>=ma;j--){
						if(x&p[j]) sum[j]++;
						if(sum[j]>m) ma=max(ma,j);
					}
					s.push(x);
				}
			}
		}
		else{
			cnt--;
			while(!s.empty()){
				int x=s.front();s.pop();
				if(x&p[i]){
					for(int j=i-1;j>=ma;j--){
						if(x&p[j]) sum[j]++;
						if(sum[j]>m) ma=max(ma,j);
					}
					q.push(x);
				}
			}
		}
	}
	cout<<res;
	return 0;
}
