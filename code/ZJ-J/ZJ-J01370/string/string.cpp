#include<bits/stdc++.h>
using namespace std;
int n;long long ans,c=0,b=0;
struct dog{
	int x;
	char y;
};
dog a[200002];int sum=0,cnt=0,xx=0,xxx;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		c+=a[i].x;
	}
	b=0;xxx=n+1;
	while(1){
		//cout<<cnt<<" "<<sum<<" "<<b<<" "<<ans<<endl;
		if(sum==0){
			xxx--;
			sum=a[xxx].x;
		}
		if(cnt==0){
			xx++;
			cnt=a[xx].x;
		}
		if(a[xx].y!=a[xxx].y){
			if(cnt>=sum){
				if(b+sum>=(c/2)){
					ans+=(c/2-b);
					break;
				}
				b+=sum;
				ans+=sum;
				cnt-=sum;
				sum=0;
			}
			else{
				if(b+cnt>=(c/2)){
					ans+=(c/2-b);
					break;
				}
				b+=cnt;
				ans+=cnt;
				sum-=cnt;
				cnt=0;
			}
		}
		else{
			if(cnt>=sum){
				if(b+sum>=(c/2)){
					break;
				}
				b+=sum;
				cnt-=sum;
				sum=0;
			}
			else{
				if(b+cnt>=(c/2)){
					break;
				}
				b+=cnt;
				sum-=cnt;
				cnt=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
