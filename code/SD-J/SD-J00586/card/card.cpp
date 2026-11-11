#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	map<int,int>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int cnt=0;
		int sum=n;
		for(int i=1;i<=n;i++){
			cnt+=sum--;
		}cout<<cnt;
		return 0;
	}
	int sum1=0,sum2=0,cnt1=0,cnt2=0;
	if(m==2){
		int x1=a[1],x2;
		for(int i=1;i<=n;i++){
			if(a[i]!=x1){
				x2=a[i];break;
			}
		}
		for(int i=1;i<=n;i++){
			cnt1+=(a[i]==x1?1:0);
			cnt2+=(a[i]==x2?1:0);
		}
		for(int i=1;i<=n;i++){if(cnt1%2)sum1++;
		if(cnt2%2)sum2++;
			if(a[i]==x1)cnt1--;
			else cnt2--;
		}
		if(cnt1%2)sum1++;
		if(cnt2%2)sum2++;
	}
	cout<<sum1<<" "<<sum2;
	
	return 0;
}

