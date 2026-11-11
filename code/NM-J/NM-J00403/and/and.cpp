#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,ans,a[2*N],ec[40],maxn=INT_MIN;
string s[2*N];
int fs[2*N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long k=0;
	for(int i=1;i<=n;i++){
	    for(int j=i+1;j<=n;j++){
	    	if(maxn<(a[i]&a[j])){
	    		maxn=a[i]&a[j];
	    		if(a[i]>a[j]){
	    			k=i;
				}else{
					k=j;
				}
			}
		}
	}
	m--;
	fs[k]=1;
	ans=maxn;
	while(m--){
		maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			if(fs[i]==1) continue;
			if((ans&a[i])>maxn){
				maxn=(ans&a[i]);
				k=i;
				
			}
	    }
	    ans=(ans&a[k]);
	    fs[k]=1;
	}
	
	cout<<ans;
	return 0;
} 
