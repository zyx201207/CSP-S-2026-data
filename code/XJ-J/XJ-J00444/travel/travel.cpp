#include<bits/stdc++.h>
using namespace std;
bool cmp;
string c1,s2,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    //shifouzaitongyijiechuxiang
	if(c1==c2 && c1!=1 && c2!=1 && c2!=16 && c2!=16){
    	cout<<1;
    	//ruguoziatongyijiechuxiang,namepanduanshifouzaitongyipai
    	for(int i=0;i<3-1;i++){
		    if(s1[i]==s2[i]) cmp=1;
		    else cmp=0;
	    }
	    if(cmp==1) {//ruguozaitongyipai,namexianshuchuzaipanduanshifouziaguodaodetongyice
	    	cout<<1;
	    	for(int i=0;i<3-1;i++){
		        if((s1[i]>='A' && s1[i]<='C' && s2[i]>='A' && s2[i]<='C') || (s1[i]>='D' && s1[i]<='F' && s2[i]>='D' && s2[i]<='F') cmp=1;
	    	    else cmp=0;
	        }
	        if(cmp==1){//ruguozaitongyice,panduanshifouxianglin
	        	cout<<1;
	        	for(int i=0;i<3-1;i++){
	        		if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) cmp=1;
	        		else cmp=0
				}
				if(cmp==1) cout<<1;
				else cout<<0;
			}
			else cout<<0;
	    }
	    else cout<<0;
	    
	}
	else cout<<"0000";
	return 0;
	
}
