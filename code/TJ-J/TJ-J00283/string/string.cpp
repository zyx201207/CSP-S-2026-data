#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int n; 
char a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int tot=0;
    while(n--){
    	int x;
    	char c;
    	cin>>x>>c;
    	for(int i=1;i<=x;i++){
    		a[tot+i]=c;
		}
		tot+=x;
	}
    int l=tot/2;
    int r;
    if(tot%2==0){
    	r=l+1;
	}else{
		r=l+2;
	}
    int ans=0;
    while(l>=1&&r<=tot){
    	if(a[l]!=a[r]){
    		ans++;
    		l--;
    		r++;
		}else{
			l--;
			r++;
		}
	}
	cout<<ans;
    return 0;
}

