#include<bits/stdc++.h>
using namespace std;

int a[200005],n,m,b[300005],c[200005] = {},ans = 0;
bool flag1 = true;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	if(a[i] > a[i - 1] && i > 1) flag1 = false;
	}
	if(flag1){
		a[n + 1] = 0x3f3f3f3f;
		for(int i = 1;i <= m;i++){
			cout << upper_bound(a + 1,a + n + 2,i) - a - 1 << " ";
		}
	}
	else{
		for(int k = 1;k <= m;k++){
		    ans = 0;
			for(int i = 1;i <= n;i++){
			    for(int j = 1;j <= m;j++){
			    	b[j] = 0;
				}
			    int e = 0;
			    for(int j = i;j <= n;j++){
			    	if(!b[a[j]]){
			    		c[++e] = a[j];
						b[a[j]] = e;
			    	}
			    	else{
			    		e = b[a[j]];
			    	}
			    }
			    for(int j = 1;j <= e;j++){
			    	if(c[j] == k){
			    		ans++;
			    		break;
					}
			    }
		    }
		    cout << ans << " "; 
		}
	}
    return 0;
}