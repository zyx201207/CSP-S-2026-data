#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,head=1,tail,ans=0;
	cin>>n;
	tail=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(head<tail){
		if(c[head]==c[tail]){
			if(a[head]<a[tail]){
				a[tail]-=a[head];
				head++;
			}else if(a[head]==a[tail]){
				head++;
				tail--;
			}else{
				a[head]-=a[tail];
				tail--;
			}
		}else{
			ans+=min(a[head],a[tail]);
			if(a[head]<a[tail]){
				a[tail]-=a[head];
				head++;
			}else if(a[head]==a[tail]){
				head++;
				tail--;
			}else{
				a[head]-=a[tail];
				tail--;
			}
		}
	}
	cout<<ans;
	return 0;
}

