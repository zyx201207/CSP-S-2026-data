#include<bits/stdc++.h> 
using namespace std;
long long a[1000001];
long long n,m;
long long ans=0,p=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	queue<int>q;
	for(int i=0;i<n;i++){
		if(!q.empty()){
			q.push(a[i]);
			m-=(a[i]-a[i-1])*(q.size()-1);p++;
			while(m<0){
				m+=a[i]-q.front();
				q.pop();
				p--;
			}
		}else{
			q.push(a[i]);
			p++;
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}
