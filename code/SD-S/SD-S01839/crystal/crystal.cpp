#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long  a[N],b[N],m;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	     b[i]=0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
	    b[i]=b[i-1]+1;
		}
	}
	int ans=0;
    for(int i=n;i>=2;i--){
    	long long cnt=0;
    for(int j=i-1;j>=1;j--){
    	cnt+=a[i]-a[j];
    	if(m==cnt){
    		ans=max(ans,i-j+1);
    		break;
		}else if(m<cnt){
			ans=max(ans,i-j);
			break;
		}
	}
	if(b[i]!=0)i-=b[i];
	if(i<=ans){
		cout<<ans;
		return 0;
	} 
	}
	return 0;
}
