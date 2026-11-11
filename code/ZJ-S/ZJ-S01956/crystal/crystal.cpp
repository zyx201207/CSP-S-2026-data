#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500001];
int s[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int cnt=0;
    int l=1,r=1;
    while(l<=r and r<=n){
    	if(s[r]-s[l]+a[l]+m>=(r-l+1)*a[r+1]){
    		r++;
		}
		else{
			if(r-l+1>cnt){
				cnt=r-l+1;
			}
			l++;
		}
	}
	if(r-l+1>cnt){
		cnt=r-l+1;
	}
	cout<<cnt;
    return 0;
}
