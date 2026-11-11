#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	long long maxx=1;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long goal=a[i];
		long long rest=m;
		long long num=0;
		for(int j=i;j>=0;j--){
			if(rest!=0&&a[j]+rest>=goal){
				num++;
				rest=rest-(goal-a[j]);
			}
			else break;
		}
		maxx=max(maxx,num);
	}
	cout<<maxx;
	return 0;
} 
