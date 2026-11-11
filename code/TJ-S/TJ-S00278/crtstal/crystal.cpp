#include<bits/stdc++.h>
using namespace std;
long long crys[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>crys[i];
	}	
	sort(crys+1,crys+1+n);
	for(int i=1;i<=n;i++){
		crys[i]=crys[i+1]-crys[i];
	} 
	int maxN=-1;
	int res=0;
	if(n<=5000){
        for(int i=1;i<=n;i++){
    	    int cnt=0,MaxN=0;;
    	    for(int j=i;j<=n;j++){
    		    if(cnt>=m){
    			    break;
			    }
    		    cnt+=crys[j]; 
    		    MaxN++;
		    }
		    if(maxN<cnt){
			    maxN=cnt;
			    res=max(res,MaxN);
		    }
	    }
	}
	else{
		int res=0;
		for(int i=1;i<=n;i++){
			if(m-crys[i]<0){
                cout<<res;
				return 0;
			}
			res++;
			m-=crys[i];
		}
	}
	cout<<res;
	return 0;
} 
