#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005]={},ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==2 and n<=2000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(ans<a[i]&a[j])ans=a[i]&a[j];
            }
        }
	}
	else if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
	}
	else{
        ans=a[n];
        for(int i=n-m+1;i<=n;i++){
            ans=ans&a[i];
        }
	}
	cout<<ans;
	return 0;
}
