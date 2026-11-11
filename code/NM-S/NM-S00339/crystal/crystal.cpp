#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005]={},s,j=0,x=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    for(int i=1;i<m-1;i++){
	    if(n%2==1){
   		 	s=a[n/2];
		}
		else{
			s=a[n/2-1];
		}
        if((s-a[i-1])>m){
            break;
        }
        else{
        	if(a[i]!=s||i<s||a[i]){
				a[i]=s;
        		m-=(s-a[i]);	
			}
            else{
        		continue;          	
			}	
		}
    }
    for(int i=0;i<=n;i++){
        if(a[i]==s){
            j++;
        }
    }
    cout<<j;    
    return 0;
}
