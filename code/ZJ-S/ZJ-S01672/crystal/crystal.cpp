#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=0;
	long long ans=1;
	deque<int> q;
	q.push_back(1);
	long long sum=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			sum++;
			q.push_back(i);
			ans=max(ans,sum);
		}
		else{
			k=k+(a[i]-a[i-1])*sum;
			while(k>m){
				long long cha=a[i]-a[q.front()];
				q.pop_front();
				k-=cha;
				sum--;
			}
			sum++;
			q.push_back(i);
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}