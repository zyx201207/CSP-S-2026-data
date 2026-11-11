#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,a[N],ans=1,id,maxn;
long long m,m1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	m1=m;
	sort(a+1,a+n+1);
	for(int i=1;i<=3;i++){
		ans=1;
		id=i;
		m=m1;
		while(m>=0){
			m-=ans*(a[id+1]-a[id]);
			if(m>=0){
				ans+=1;
				id++;
			}
			else{
				break;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
