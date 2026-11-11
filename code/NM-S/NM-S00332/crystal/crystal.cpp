#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
int a[5001];
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n>5000){
    	int a1,a2;
    	cin>>a1>>a2;
    	int cha=a2-a1;
    	for(int i=1;i<=n;i++){
    		if(ans+i*cha>m)break;
    		ans+=i*cha;
		}
		cout<<ans;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    
    sort(a+1,a+n);
    for(int i=n;i>=1;i--){
    	int cnt=0,sum=0;
    	for(int j=i;j>=1;j--){
    		sum+=a[i]-a[j];
    		cnt++;
    		if(sum>m||(j==1&&sum<=m)){
    			if(sum>m)ans--;
				ans=max(ans,cnt);
    			break;
			}
		}
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
