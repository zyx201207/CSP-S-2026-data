#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char y;
}a[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); 
	long long n,k=0,ans=0;
	queue<node> q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	q.push(a[n]);
	for(int i=1;i<n-k;i++){
		while(a[i].x>0){
			if(q.front().x==0){
				k++;
				if(n-k>i){
					q.pop();
					q.push(a[n-k]);
				}
				else{
					break;
				}
			}
			if(a[i].y!=q.front().y){
				if(a[i].x>=q.front().x){
					ans+=q.front().x;
					a[i].x-=q.front().x;
					q.front().x=0;
				}
				else{
					ans+=a[i].x;
					q.front().x-=a[i].x;
					a[i].x=0;
				}
			}
			else{
				if(a[i].x>=q.front().x){
					a[i].x-=q.front().x;
					q.front().x=0;
				}
				else{
					q.front().x-=a[i].x;
					a[i].x=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
