#include<iostream> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m,x,tidai,mubiao,cd,shuliang;
    long long shu[10005];
    long long changdu[10005];
    long long fushu[10005];
    long long shuliang1[10005];
    cin>>n>>m;
    int mid=n/2+1;
	for(int i=1;i<=n;i++){
		cin>>shu[i];
    }
    for (int i= 1; i<=n;i++){
    	for (int j =1;j<=n;j++){
    		if(shu[j]>=shu[j+1]){
                tidai=shu[j];
                shu[j]=shu[j+1];
                shu[j+1]=tidai;
			}
		}
	}
	for(int i=1;i<=n;i++){
		mubiao=shu[i];
		for (int j =1;j<=n;j++){
			cd=shu[j]-mubiao;
			changdu[j]=cd;
	    }
	    for (int j =1;j<=n;j++){
			if (changdu[j]<0){
				fushu[j]=changdu[j];
				x=x+1;
		    }
	    }
		for (int o= 1; i<=x;i++){
    	    for (int j =1;j<=x;j++){
    		    if(fushu[j]>=fushu[j+1]){
                    tidai=fushu[j];
                    fushu[j]=fushu[j+1];
                    fushu[j+1]=tidai;
				}
			}          
		}
		shuliang=0;
		for(int j=1;j<=x;j++){
			while(fushu[x-j+1]<0){
				fushu[x-j+1]=fushu[x-j+1]+1;
				m=m-1;
		        if (m=0){
		        	break;
				}				    
			}   
			shuliang=shuliang+1;  
		}
		shuliang1[i]=shuliang;
			
	}
	for (int i= 1; i<=n;i++){
    	for (int j =1;j<=n;j++){
    		if(shuliang1[j]>=shuliang1[j+1]){
                tidai=shuliang1[j];
                shuliang1[j]=shuliang1[j+1];
                shuliang1[j+1]=tidai;
			}
		}
	}
	cout<<shuliang1[n]<<" ";
      
	return 0;
}
					
