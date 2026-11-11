#include<bits/stdc++.h>
using namespace std;
int n,a[200010],cnt;long long ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		int now=cnt;
		int f=0;
		for(int j=now;j>=1;j--){
            if(i==j){
                f=1;
                break;
            }
			if(a[i]>=a[j]){
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				a[i]-=a[j];
				a[j]=0;
			}
			else{
				cnt=j;
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				a[j]-=a[i];
				break;
			}
		}
		if(f==1)break;
	}
	cout<<ans;
	return 0;
}
