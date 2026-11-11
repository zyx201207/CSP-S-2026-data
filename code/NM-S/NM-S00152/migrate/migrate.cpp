#include<bits/stdc++.h>
using namespace std;
long long a[300000];
int www(int start,int end,int d){
	int now;
	now=start;
	int bu=0;
	while(now!=end){
		int l=0;
		if(d>=a[end]-a[now]){
			bu++;
			break;
		}
		while(l<=d){
			l=l+a[now+1]-a[now];
			if(l>d){
				break;
			}
			now++;
		}
		bu++;
	}
	return bu;
}
int yyy(int start,int end,int d,int bu){
	int now;
	int sum=0;
	now=start;
	if(bu>0){
		if(a[end]-a[now]<=d){
			sum++;
			return sum;
		}
		else{
			int l=0;
		    int k[300000];
		    int i=0;
		    while(1){
			    l=l+a[now+1]-a[now];
			    if(l>d){
				    break;
			    }
			    k[i]=now+1;
			    now++;
			    i++;
		    }
		    if(a[end]-a[now]>d){
			    for(int r=0;r<i;r++){
			        sum=sum+yyy(k[r],end,d,bu-1);
			    } 
		    }
		}
	}
	return sum;
}
int main(){
	int w[100000];
	int c,t,qqq=0;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int q=1;q<=n;q++){
			cin>>a[q];
		}
    
        int fff=1;
        int kkk=1;
        int hhe=0;
	    for(int iii=1;iii<=n;iii++){
		    if(a[iii+1]-a[iii]>=d||fff==n){
		    	for(int o=kkk;o<=fff;o++){
			    	for(int oo=o+1;oo<=fff;oo++){
			    		int e=www(o,oo,d);
			    		int he=yyy(o,oo,d,e+1);
			    		if(he!=2){
			    			he=0;
						}
			    		hhe=hhe+he;
				    }
		    	}    
		    	kkk=fff+1;
	    	}
	    	fff++;
	    }	
	    w[i-1]=hhe;
	    qqq++;
    }
    for(int rrr=0;rrr<qqq;rrr++){
    	cout<<w[rrr]<<endl;
	}
	return 0;
}
