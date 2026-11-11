#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long a[N],l[N],r[N],z[N];
priority_queue<long long>q,q1;
map<long long,long long>b,b1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		z[i]=z[i-1]+a[i];
	}
	long long start=1,end=1,cost,maxx,ans1=1,num;
	q.push(a[1]);
	b[a[1]]++;
	while(start<=n&&end<=n){
		num=end+1-start;
		while(1){
			if(b[q.top()]>0){
				maxx=q.top();
				break;
			}
			else q.pop();
		}
		cost=(maxx*num)-(z[end]-z[start-1]);
		if(cost<=m){
			ans1=max(ans1,num);
			end++;
			q.push(a[end]);
			b[a[end]]++;
		}
		else{
			b[a[start]]--;
			start++;
		}
	}
	start=n,end=n,cost=0,maxx=0,num=0;
	q1.push(a[n]);
	b1[a[n]]++;
	while(start>=1&&end>=1){
		num=end+1-start;
		while(1){
			if(b1[q1.top()]>0){
				maxx=q1.top();
				break;
			}
			else q1.pop();
		}
		cost=(maxx*num)-(z[end]-z[start-1]);
		if(cost<=m){
			ans1=max(ans1,num);
			start--;
			q1.push(a[start]);
			b1[a[start]]++;
		}
		else{
			b1[a[end]]--;
			end--;
		}
	}
	cout<<ans1<<endl;
	return 0;
}
