#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
    cin>>n>>m;
    int a[n];
    for(int i = 0; i<n; i++){
      	cin>>a[i];
    }
    bool flag = true;
    if(n>=2){
    	int mns = a[1]-a[0];
    	for(int i = 2; i<n; i++){
    		if(a[i]-a[i-1] != mns){
    			flag = false;
    			break;
			}
		}
		if(flag){
			int res = 1;
			int temp = mns;
			int limit = m;
			while(temp<=limit){
				res++;
				limit-=temp;
				temp=res*mns;
			}
			cout<<res<<"\n";
			return 0;
		}
	}


    int diff[n];
    sort(a,a+n);
    diff[0] = 0;
    for(int i = 1; i<n; i++){
      	diff[i] = a[i]-a[i-1];
    }
    int res = 1;
    for(int i = n-1; i>=0; i--){
        int ans = 1;
        int temp = 0;
        int limit = m;
        for(int j = i; j>=1; j--){
        	temp+=diff[j];
            if(temp<=limit){
	          	ans++;
	          	limit-=temp;
          	}
        	else{
          		break;
        	}
      	}
	    res = max(res, ans);
		if(res >= i) break;
    }
	cout<<res<<"\n";
	return 0;
}

