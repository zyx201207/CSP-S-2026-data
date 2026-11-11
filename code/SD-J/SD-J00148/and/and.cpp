#include<bits/stdc++.h>//25pts+ £¨Ãÿ ‚–‘÷  
using namespace std;
#define ll long long
ll i,j;
ll n,m;
ll a[200005];
priority_queue<ll> pq;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ll biggg=-1e18,all=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		biggg=max(a[i],biggg);
		if(i==0)all=a[i];
		else{
			all&=a[i];
		}
		pq.push(a[i]);
	}
	if(m==1){//5pts
		cout<<biggg;
		return 0;
	}
	if(n==m){//5pts
		cout<<all;
		return 0;
	}
	if(m==n-1){
		ll cccc=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j==i)continue;
				if(i!=0&&j==0)cccc=a[j];
				else if(i==0&&j==1)cccc=a[j];
				else cccc&=a[j];
			}
		}
		cout<<cccc;
		return 0;
	}
	if(m==2&&n<=10000){//15pts
		ll maxn=-1e18;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				ll qoq=a[i],qqqq=a[j];
				qoq&=qqqq;
				maxn=max(qoq,maxn);
			}
		}
		cout<<maxn;
		return 0;
	}
	ll fun=pq.top();
	pq.pop();
//	cout<<fun<<" "<<pq.top()<<endl; 
	if(!pq.empty()){
		for(i=1;i<m;i++){
		    fun&=pq.top(); 
		    pq.pop();
		}
	}
	cout<<fun;
	return 0;
}

