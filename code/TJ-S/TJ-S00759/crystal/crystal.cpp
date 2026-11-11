#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005];
int cnt=0,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==i) ans++;
	}
	for(int i=1;i<=m;i++){
		sort(a+1,a+n+1);
		a[1]+=1;	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[i]==a[i+1]){
				cnt++;
			}
		}
		if(a[i]==a[i-1]){
			cnt++;
		}
	}
	if(ans==n){
		cout<<cnt+1;
	}else{
		cout<<cnt;
	}
    return 0;
}
