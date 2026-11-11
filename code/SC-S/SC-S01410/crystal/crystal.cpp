#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int crystal[10000000];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>crystal[i];
    }
    int setgoals,laps,maxs;
    sort(crystal,crystal+n);
    for(int j=0;j<n;j++){
        setgoals=j+1;
        //cout<<setgoals<<" "<<endl;
        for(int laps=0;laps<setgoals-1;laps++){
            int startpos=laps;
            int count=0;
            //cout<<startpos<<" "<<count<<" "<<endl;
            for(int p=startpos;p<setgoals;p++){
                count+=crystal[p];
                //cout<<"!!"<<count<<" "<<endl;
            }
            //cout<<count<<" "<<endl;
            //cout<<count+m<<" "<<endl;
            //cout<<setgoals-startpos<<" "<<endl;
            //cout<<"$"<<((count+m)%(setgoals-startpos))<<" "<<endl;
            if((count+m)%(setgoals-startpos)==0){
                int r=0,counts=0;
                for(int y=startpos;y<setgoals-1;y++){
                    //cout<<y<<crystal[y];
                    r=crystal[y]-((count+m)/(setgoals-startpos));
                    if(r<0){
                        r=r/-1;
                    }
                    //cout<<"*"<<r<<endl;
                    counts+=r;
                }
                //cout<<"counts"<<counts<<endl;
                if(setgoals-(startpos)>maxs && counts==m){
                    maxs=setgoals-(startpos);
                    //cout<<"Getmax"<<maxs<<"sp"<<startpos<<"sg"<<setgoals<<" "<<endl;
                }
            }
            startpos++;
        }
    }
    cout<<maxs;
    return 0;
}