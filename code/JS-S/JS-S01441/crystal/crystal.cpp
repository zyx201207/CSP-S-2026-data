#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long tmp,ans,k;
void biao(int x){
	k=m;
	tmp=0;
    for(int i=x;i>=1;i--){
		if(k-(a[x]-a[i])>=0){
			k=k-(a[x]-a[i]);
			tmp++;
	    }
	    else
	    break;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=5000){
		for(int i=n;i>=1;i--){
			biao(i);
			ans=max(ans,tmp);
	    }
	    cout<<ans;
    }
    else{
	    biao(n);
	    cout<<tmp;	
    }
    return 0;
}
