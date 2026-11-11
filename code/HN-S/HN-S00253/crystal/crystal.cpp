#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,a[250000],ans1=0;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int b[250000]={0x3f3f3f3f};
	    int ans=0;
        for(int j=1;j<=n;j++){
    	    if(a[j]>a[i]){
    	    	continue;
			}
			if(a[j]==a[i]){
				ans++;
    	    	continue;
			}
			b[j]=a[i]-a[j];
	    }
	    sort(b+1,b+n+1);
	    int m1=m;
	    for(int j=1;j<=n;j++){
	    	if(b[j]==0x3f3f3f3f||b[j]==0){
	    		continue;
			}
			if(m1>0){
				m1-=b[j];
				ans++;
		    }
		    if(m1==0){
		    	break;
			}
			if(m1<0){
				ans--;
				break;
			}  
		}
		ans1=max(ans,ans1);	
	}
	cout<<ans1;
	return 0;
}
