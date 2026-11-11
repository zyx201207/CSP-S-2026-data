#include<bits/stdc++.h> 
using namespace std;
long long a[500005];
long long n,m,cnt,k=1,k1,r=1;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		//i=1时侯k=1,cnt=0
		//右移一位
		k++;
		cnt+=(k-1)*(a[i]-a[i-1]);
		while(cnt>m){
			if(cnt>m){
				//过于昂贵则扔
				cnt-=(a[i]-a[r]);
				//扔掉r号
				r++;
				k--;
			}
		}
		k1=max(k,k1);
	}
	cout<<k1;
	return 0;
}
