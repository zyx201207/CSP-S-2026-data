#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int head=1,rear=n;
	while(head<rear){
		if(c[head]!=c[rear]){
			if(a[head]==a[rear]){
				ans+=a[head];
				head++;
				rear--;
				continue;
			}
			bool fl=0,ag=0;
			if(min(a[head],a[rear])==a[head])fl=1;
			else ag=1;
			if(fl){
				ans+=a[head];
				a[rear]-=a[head];
				head++;
				continue;
			}else{
				ans+=a[rear];
				a[head]-=a[rear];
				rear--;
				continue;
			}
		}else{
			if(a[head]==a[rear]){
				head++;
				rear--;
				continue;
			}bool fl=0,ag=0;
			if(min(a[head],a[rear])==a[head])fl=1;
			else ag=1;
			if(fl){
				a[rear]-=a[head];
				head++;
				continue;
			}else{
				a[head]-=a[rear];
				rear--;
				continue;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
