#include<bits/stdc++.h>
using namespace std;


struct node{
	int chixiang;
	int zuiwie;
	char zimu;
}a[1000000];



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++) cin>>a[i].chixiang>> a[i].zuiwie>>a[i].zimu;
	//两张车票对应的座位是否在同一节车厢
	if(a[1].chixiang==a[2].chixiang){
	    cout<<1;
	    //两张车票对应的座位是否在同一节车厢的同一排;
	    if(a[1].zuiwie==a[2].zuiwie){
			cout<<1;
			//两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
			if((a[1].zimu=='A'||a[1].zimu=='B'||a[1].zimu=='C')&&(a[2].zimu=='A'||a[2].zimu=='B'||a[2].zimu=='C')){
				cout<<1;
				//两张车票对应的座位是否相邻。
				if(a[1].zimu=='A'&&a[2].zimu=='B')
				    cout<<1;
				else if(a[1].zimu=='B'&&(a[2].zimu=='A'||a[2].zimu=='C'))
				    cout<<1;
				else if(a[1].zimu=='C'&&a[2].zimu=='B')
				    cout<<1;
				else
				    cout<<0;
				return 0;    
				
			}
			
			else if( (a[1].zimu=='D'||a[1].zimu=='F') && (a[2].zimu=='D'||a[2].zimu=='F') ){
			    cout<<1;
			    cout<<1;
		    }		    
			else{
			   cout<<"00";
			   return 0;
		   }
		}
		else{
			cout<<"000";
			return 0;
		}	 	    	
	}
	
	//NIHAO!!!!
	else{
		for(int i=1;i<=4;i++){
			cout<<0;
		}
	}					
    return 0;   
}
