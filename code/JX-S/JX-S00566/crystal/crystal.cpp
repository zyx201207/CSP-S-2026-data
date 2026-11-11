#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500010],m,Max=0,b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=1,M=m;
	for(int i=2;i<=n;i++){
		if(M>=cnt*(a[i]-a[i-1])){
			M-=cnt*(a[i]-a[i-1]);
			cnt++;					
		}else{
			while(cnt!=1){
				cnt--;
				M+=(a[i-1]-a[i-cnt-1]);
				if(M>=cnt*(a[i]-a[i-1])){
					M-=cnt*(a[i]-a[i-1]);
					cnt++;
					break;		
				}									
			}
		}
		Max=max(Max,cnt);
	}
	cout<<Max;
	return 0;
}
