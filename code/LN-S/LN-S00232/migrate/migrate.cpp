#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,cnt=0;
    cin>>c>>t;
    for(int ih=0;ih<t;ih++){
        int n,d;
        cin>>n>>d;
        int x[n],x1[n],shu=1;
        for(int i=0;i<n;i++){
            cin>>x[i];
            if(i=0)
                x1[i]=0;
            else if(x1[i-1]==-1)
                x1[i]=-1;
            else if(x[i]-x[i-1]<d||x[i]-x[i-1]==d){
                x1[i]=i;
                shu+=1;
            }

            else
                x1[i]=-1;
        }
        int tiao=0,minn=0,biao=0,bushu=0;
        for(int i=0;i<shu;){
            for(int j=i+1;j<=shu;j++){
                if(x[j]-x[i]==d){
                    i=j;
                    minn+=1;
                    biao=0;
                    break;
                }else if(x[j]-x[i]>d){
                    j-=2;
                    biao=1;
                }else if(x[j]-x[i]<d&&biao==1){
                    i=j;
                    minn+=1;
                    biao=0;
                    break;
                }
            }
        }
        for(int st=0;st<shu-1;st++){
            for(int i=st;i<shu;){
                for(int j=i+1;j<=shu;j++){
                    if(x[j]-x[i]==d){
                        i=j;
                        bushu+=1;
                        biao=0;
                        break;
                    }else if(x[j]-x[i]>d){
                        j-=2;
                        biao=1;
                    }else if(x[j]-x[i]<d&&biao==1){
                        i=j;
                        bushu+=1;
                        biao=0;
                        break;
                    }
            }

        }
        if(bushu==minn)tiao+=1;
            if(tiao==2)cnt+=1;
        }
        for(int st=shu;st>0;st--){
            for(int i=0;i<st;){
                for(int j=i+1;j<=shu;j++){
                    if(x[j]-x[i]==d){
                        i=j;
                        bushu+=1;
                        biao=0;
                        break;
                    }else if(x[j]-x[i]>d){
                        j-=2;
                        biao=1;
                    }else if(x[j]-x[i]<d&&biao==1){
                        i=j;
                        bushu+=1;
                        biao=0;
                        break;
                    }
            }

        }
        if(bushu==minn)tiao+=1;
            if(tiao==2)cnt+=1;
        }
        cout<<cnt;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
