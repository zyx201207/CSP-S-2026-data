#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long no=0,ne=0,t=0,nt=0;
int sum=0;
int max_sum=0;
queue<long long>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i+1]==a[i]){
			q.push(a[i]);
			i++;
			sum++;
		}
		ne+=(no-nt)*(a[i]-a[no]);
		q.push(a[i]);
		sum++;
		if(ne>m){
			while(!q.empty()&&ne>m){
				long long x=q.front();
				ne-=a[i]-x;
				q.pop();
				nt++;
			}
			sum=0;
		}else{
			max_sum=max(sum,max_sum);
		}
		no=i;
	}
	cout<<max_sum;
	return 0;
}
