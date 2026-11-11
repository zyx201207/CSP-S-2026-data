#include<bits/stdc++.h>
using namespace std;
char cr[5],sr[5],cx[5],sx[5];
int ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>cr[1]>>cr[2];
	cin>>sr[1]>>sr[2]>>sr[3];
	cin>>cx[1]>>cx[2];
	cin>>sx[1]>>sx[2]>>sx[3];
	bool flag=true;
	for(int i=1;i<=2;i++){
		int a=cr[i]-48;
		int b=cx[i]-48;
		if(a!=b)  flag=false;
	}
	if(flag==true){
		ans[1]=1;
		flag=true;
	    for(int i=1;i<=2;i++){
		    int a=sr[i]-48;
		    int b=sx[i]-48;
		    if(a!=b)  flag=false;
	    }
	    if(flag==true){
	    	flag=true;
	    	ans[2]=1;
	    	int a=sr[3]-65;
	    	int b=sx[3]-65;
	    	if(a<3&&b<3)  flag=true;
	    	else{
	    		if(a>2&&b>2)  flag=true;
	    		else  flag=false;
			}
			if(flag==true){
				ans[3]=1;
				if(a>2&&b>2)  flag=true;
				else{
					int t;
					if(a>b)  t=a-b;
					else t=b-a;
					if(t==1)  flag=true;
					else  flag=false;
				}
				if(flag==true)  ans[4]=1;
				else  ans[4]=0;
			}
			else{
				ans[3]=0;
				ans[4]=0;
			}
		}  
		else{
			for(int j=2;j<=4;j++){
				ans[j]=0;
			}
		}  
	}  
	else{
		for(int j=1;j<=4;j++){
			ans[j]=0;
		}
	}  
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}