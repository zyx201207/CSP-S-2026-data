#include<bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
char c[10];
char d[10];
int main(){
	freopen("travel.im","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	long long i=1;
	int x=1;
    while(i<=1){   
    	if(i>2){
    		break;
		}
		//cout<<a[i]<<" "<<c[i]<<endl;
    	if(a[i]!=c[i]){
    	    x=0;
		}
		else{
		    x=1;
		}
		i++;
		//cout<<x<<endl;
	}
	if(x==0){
		cout<<"0"<<"0"<<"0"<<"0";
    		return 0;
	}
	if(x==1){
		cout<<"1"<<"1"<<"1"<<"1";
			
	}	
	i=0;
	
	//while(i<=3){
	//	if(b[i]==d[i]){
	//	    cout<<"1";	
	//	}
		/*if(i==3){
			b[i]=b[i]-'0';
			d[i]=d[i]-'0';
			if(b[i]-d[i]>='D'-'A'){
				cout<<"0";
			}
			else{
				cout<<"1";
			}
			if(b[i]==d[i]){
				cout<<"1";	
			}
			else{
				cout<<"0";
			}
		}
		i++;*/
	
	return 0;
}
