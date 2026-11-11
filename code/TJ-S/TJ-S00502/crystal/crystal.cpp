#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],an[500010],sum,target,ans;
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int left=0;
    int right=n;

    while(left<=right){
    	int mid=(left+right)/2;
		for(int i=0;i<mid;i++){
	    	if(a[i]<a[mid]){
	    		an[i]=a[mid]-a[i];
	    		sum+=an[i];
			}
		}
		if(sum>m){
			right=mid-1;
			continue;
		}
		else if(sum<m){
			left=mid+1;
			continue;
		}
		else if(sum==m){
			target=a[mid];
			break;
		}

	}
	for(int i=0;i<n;i++){
		if (a[i]<=target){
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
