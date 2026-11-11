#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,linc,stc,lmx,q;
    long long a=0,t=0,x=INT_MAX;
    bool isd=false;
    cin>>c>>linc>>stc>>lmx>>q;
    int w[stc];
    for(int i=0;i<stc;i++){
        cin>>w[i];
    }
    int lisc[linc];
    int a1[linc][lmx];
    int t1[linc][lmx];
    int k1[stc][stc];
    for(int i=0;i<stc;i++){
        for (int j=0;j<stc;j++){
            k1[i][j]=-1;
            
        }
    
    }
    int r[q][2];
    for(int i=0;i<linc;i++){
        cin>>lisc[i];
        for(int j=0;j<lisc[i];j++){
            cin>>a1[i][j];
            cin>>t1[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>r[i][0];
        cin>>r[i][1];
    }
    
        for(int s=0;isd==false;s++){
		
		isd=true;
        
        for(int j=0;j<stc;j++){
            for(int j2=0;j2<stc;j2++){
                if(k1[j][j2]==-1){
					
    if(j==j2){
			k1[j][j2]=0;
    }
    t=0;
    for(int i=0;i<stc;i++){
        for(int j3=0;j3<stc;j3++){
            if((k1[j][j3]!=-1)&&(k1[j2][j3]!=-1)){
                t=k1[j][j3]+k1[j2][j3];
            }
        }
        if(t<x){
            x=t;
        }
        t=0;
	}
    for(int i=0;i<linc;i++){
		
        a=0;
        for(int s2=0;s2<lisc[i];s2++){
            if(j==a1[i][s2]){
                a=1;
                t+=t1[i][s2];
            }
        }
        for(int s1=0;s1<lisc[i];s1++){
            if((j2==a1[i][s1])&&a==1){
                t+=t1[i][s1];
            }

        }
        if(t<x){
            x=t;
        }
        
        
    }
    if(x==INT_MAX){
        k1[j][j2]=-1;
        isd=false;
        
    }else{
		k1[j][j2]=x;
    
                }
              
            x=INT_MAX;    
            }
            
        }
        }
        
     }
     for(int i=0;i<q;i++){
		 cout<<(k1[r[i][0]][r[i][1]]+w[r[i][0]]+w[r[i][1]])<<endl;
	 }
    

    
    
        
       
    return 0;
    }
