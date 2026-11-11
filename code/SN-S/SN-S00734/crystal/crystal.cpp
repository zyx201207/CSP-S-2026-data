#include<bits/stdc++.h>
using namespace std;
long long n,m;
queue<long long> q;
long long a[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long da=1,yong=0;
	if(n==1){
		cout<<1;
		return 0;
	}
	q.push(a[0]);
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			q.push(a[i]);
			long long dd=q.size();
			da=max(da,dd);
			continue;
		}
		long long ge=q.size();
		long long ch=a[i]-a[i-1];
		while((m-yong)<(ch*(ge-1)) && !q.empty()){//剩下的能量小于再来一颗水晶需要的能量 
			long long qq=q.front();
			yong-=(a[i-1]-qq);
			ge--;
			q.pop();
		}
		if(q.empty()){
			q.push(a[i]);
			continue;
		}
		q.push(a[i]);
		long long dd=q.size();
		da=max(da,dd);
		yong+=ch*(dd-1);
	}
	cout<<da;
	return 0;
} 
