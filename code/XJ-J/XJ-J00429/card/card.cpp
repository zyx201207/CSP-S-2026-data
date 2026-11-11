#include<bits/stdc++.h>
using namespace std;
int a[500000],table[500000],s[500000],a1[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a1[i-1]==a[i])break;
		else a1[i]==a[i];
	}
	for(int k=0;k<n;k++){
    	for(int i=0,j=0;i<m;i++,j++){
    		if(i+k>=m){
			s[k]=j;break;
			}
    		table[j]=a[i+k];
    		for(int q=0;q<k+i;q++){
    			if(table[q]==table[j]){
    				table[q]=table[j];
    				j-=q;
    				break;
				}
			}
    	}
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<m;i++){
        	for(int j=0;j<s[i];j++){
        		if(table[j]==a1[i])r++;
	    	}
    	}
    	if(r!=0)cout<<r<<" ";r=0;
     }
    return 0;
}