#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long ans;
long long  a[500005];
inline long long check(int idx){
	long long jj=a[idx];
	long long cost=0,cnt=1;
	int i=idx+1;
	
	while(true){
		
		if(i>n || cost+(jj-a[i])>m){
			
			return cnt;}
		else{
			cnt++;
			cost+=(jj-a[i]);
			i++;
		}
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int gc=0;
	int T=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		
	}
	sort(a+1,a+n+1,cmp);
	if(n>=500000){
		for(int i=1;i<=n;i++){
			if(i==2) gc=a[i]-a[i-1];
			else if(i==1);
			else{
				if(gc != a[i]-a[i-1]){
					T=0;
					break;
				}
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,check(i));
		if(T==1 && n>=500000){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
/*5 8
 -3 -1 2 2 7
5 5
1 2 4 8 9
*/
