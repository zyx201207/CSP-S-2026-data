#include<bits/stdc++.h>
#define int long long
using namespace std;
const int L=2e5+10;
int n,a[L],ans;
string c[L];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){		
		while(a[i]>=a[j]&&i<j){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];			
			j--;			
	    }
	    if(i>=j)break;
	    if(c[i]!=c[j]){
	    	ans+=a[i];
	        a[j]-=a[i];
		}	    
	    i++;
	}			
	cout<<ans;
	return 0;
}
