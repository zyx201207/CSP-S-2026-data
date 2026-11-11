#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5;
int main(){
	freopen(".in","r",stdin); 
    freopen(".out","w",stdout); 
    int n,a[A],ans=1;long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1); 
    for(int i=2;i<=n;i++){
    	int j;long long sum=0;
    	for(j=i-1;j>0;j--){
    		if (sum+a[i]-a[j]>m){
    			break;
			}
			else sum=sum+a[i]-a[j];
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
} 
