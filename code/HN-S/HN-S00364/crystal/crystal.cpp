#include<bits/stdc++.h>
using namespace std;
long long w,n,m,sum,sheng,maxx=-10000000000,ans;
long long t[1000007],a[1000007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	ans=1;
	    for(int j=i;j>=1;j--){
		    if(a[i]-a[j]<=m&&a[i]!=a[j]){
		        sheng=a[i]-a[j];
		        if(sum+sheng<=m){
//		        a[j]+=sheng;
		    	    sum+=sheng;
		    	    ans+=1;
			    }
			    else{
			    	break;
				}
		    }
		}
//		for(int k=1;k<=n;k++){
//			if(a[k]=a[k]+1) ans++;
//		}
	    if(ans>=maxx){
	    	w=i;
		    maxx=ans;
		}
	}
//	cout<<ans<<endl;
	cout<<maxx+t[a[w]]<<endl;
	
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
6 3
8 3 5 5 7 2
*/
