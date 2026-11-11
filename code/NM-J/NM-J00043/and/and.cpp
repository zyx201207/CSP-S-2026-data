#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	if (m==1){
		cout<<arr[n-1]<<endl;
		return 0;
	}
	int maxs=0;
	if (m==2){
    	for(int i=1;i<n;i++){
	    	for (int j=0;j<i;j++){
	    		maxs=max(maxs,(arr[i]&arr[j]));
	    		
	    	}
	    }
	    cout<<maxs<<endl;
	    return 0;
	}
	if (m==3){
		for(int i=2;i<n;i++){
	    	for (int j=1;j<i;j++){
	    		for (int k=0;k<j;k++){
	    	    	maxs=max(maxs,(arr[i]&arr[j]&arr[k]));
				}
	    	}
	    }
	    cout<<maxs<<endl;
	    return 0;
	}
	if (m==4){
		for(int i=0;i<n;i++){
	    	for (int j=1;j<n;j++){
	    		for (int k=2;k<n;k++){
	    		    for (int l=3;l<n;l++)
	    	    	    maxs=max(maxs,(arr[i]&arr[j]));
				}
	    	}
	    }
	    cout<<maxs<<endl;
	    return 0;
	}
	cout<<arr[0]<<endl;
	return 0;
}
