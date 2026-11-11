#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,len,step;
int line[500000];
int m[500000];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char a;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>a;
		line[i]=a-'a';
		len=len+m[i];
	}	
	int l=1;
	int r=n;
    while(l<=r){
    	if(line[l]==line[r]){
    		if(m[l]==m[r]){
    			l++,r--;
    			continue;
			}
    	   if(m[l]!=m[r]){
    	   	 if(m[l]>m[r]){
    	   	 	m[l]=m[l]-m[r];
    	   	 	r--;
    	   	 	continue; 
			 }
			 if(m[l]<m[r]){
			 	m[r]=m[r]-m[l];
    	   	 	l++;
    	   	 	continue;
			 }
		   }
	    }else{
	    	//
	    	if(m[l]==m[r]){
	    		step=step+m[l];
	    		l++;
	    		r--;
	    		continue;
			}
    	   	 if(m[l]>m[r]){
    	   	 	step=step+m[r];
    	   	 	m[l]=m[l]-m[r];
    	   	 	r--;
    	   	 	continue;
			 }
			 if(m[l]<m[r]){
    	   	 	step=step+m[l];
    	   	 	m[r]=m[r]-m[l];
    	   	 	l++;
    	   	 	continue;
			 }
		}
	}
    cout<<step;
}
