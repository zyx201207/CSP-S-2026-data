#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	int special=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);	
		if(i>2&&a[i]-a[i-1]==sum)special++;
		else sum=a[2]-a[1];
	}
	if(special==n-1){
		//cout<<"cao";
		for(int i=1;i<n;i++){
			int cur=sum*((1+i)*i/2);
			if(cur>m){
				cout<<i;
				break;
			}
		}
		return 0;
	} 
	sort(a+1,a+1+n);
	int x=m;
	for(int i=n;i>=1;i--){
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			int tmp=a[i]-a[j];
			if(x>=tmp){
				x-=tmp;
				cnt++;
			}else break;
		}
		ans=max(cnt,ans);
		x=m;
	}
	printf("%lld",ans);
	return 0;
} 
/*
5 5
1 3 5 7 9
0 2 2 2 2


5
1 2 4 8 9
0 1 3 7 8
sum*1+sum*2+......sum*i
(1+i)*i/2; 
8
0 -3 -1 2 2 7
0  0  2 3 0 5
   0  2 5 5 10
45超时贪心+30分特判=75分   
Oct31==Dec25?
*/

