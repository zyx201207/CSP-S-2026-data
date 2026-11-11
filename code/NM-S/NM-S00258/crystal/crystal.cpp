#include<bits/stdc++.h>
using namespace std;
long long n,f,w,sum;
const long long N=1e6;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>f;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
	sort(a,a+n);
	for(long long i=0;i<n;i++){
        if(a[i]==a[i+1]){
        	sum+=1;
		}
    }
        for(long long i=0;i<n;i++){
            for(long long j=i-1;j>=0;j--){
            	w+=(a[i]-a[j]);
            	if(w<=f){
            		sum+=1;
            		a[i]=a[j];
				}else{
					continue;
				}
        	}
        }

		cout<<sum;
    return 0;
}
