#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        //scanf("%ld%c",&a[i],&c[i]);
        cin>>a[i]>>c[i];
    }
    long long i=1,j=n,sum=0;
    while(i<=j){
    	long long x=a[i]-a[j];
    	int minn=min(a[i],a[j]);
    	if(x>0){
    		if(c[i]==c[j]){
    			a[i]=x;
    			j--;
			}else{
    			a[i]=x;
    			j--;	
				sum+=minn;			
			}
		}else{
			if(x<0){
				x=-x;
    			if(c[i]==c[j]){
    				a[j]=x;
    				i++;
				}else{
    				a[j]=x;
    				i++;	
					sum+=minn;			
				}
			}else{
	    		if(c[i]==c[j]){
    				j--;
    				i++;
				}else{
    				j--;
    				i++;	
					sum+=minn;			
				}			
			}
		}
	}
	cout<<sum;
    return 0;
}