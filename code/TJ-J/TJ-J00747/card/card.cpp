#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,a[N],m,cnt[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	
	for(int t=1;t<=n;t++){
		int cnt1[N];
		for(int i=1;i<=m;i++){
			cnt1[i]=cnt[i];
		}
		for(int i=1;i<t;i++){
			if(cnt1[a[i]]>0) cnt1[a[i]]--;
		}
	    for(int i=t;i<=n;i++){
		    if(cnt1[a[i]]>=2){
			    for(int j=n;j>i;j--){
				    if(a[j]==a[i]){
					    for(int k=i;k<j;k++){
						    cnt1[a[k]]--;
					    }
					    break;
				    }
			    }
	    	}
	    }
	    for(int i=1;i<=m;i++){
	    	if(cnt1[a[i]]>0) ans[i]++;
		}
	}
	ans[a[n]]++;
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
