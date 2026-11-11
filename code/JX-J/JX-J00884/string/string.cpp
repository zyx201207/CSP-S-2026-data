#include<bits/stdc++.h>
using namespace std;
struct p{
    long long a;
    string b;

}e[20000005];
struct l{
    long long a;
    string b;

}o[20000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    bool y=1,n=0;
    long long a,b=0,c,d=1,r=0,m,sum=0,t=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>e[i].a>>e[i].b;
        b+=e[i].a;
    }
    int v=b;
    c=b;
    b/=2;

    for(int i=1;i<=a;i++){
        if(r+e[i].a<=b or y==0){
            o[d].a=e[i].a;
            o[d].b=e[i].b;
            d++;
            r+=e[i].a-1;
        }
        else if(r+e[i].a>b){
            m=d;
            int h=e[i].a-r;
            o[d].a=h;
            o[d].b=e[i].b;
            d++;
            o[d].a=e[i].a-h;
            o[d].b=e[i].b;
            d++;
            y=0;
            r+=e[i].a;
        }
    }
    t+=m+1;
    if(c%2==1){
        m--;
        v--;
    }

    while(v>0){

        if(c%2==1){

            if(o[t].b!=o[m].b){

                if(o[m].a>o[t].a){
                    sum+=o[t].a;
                    v-=2*(o[t].a);
                    o[m].a-=o[t].a;
                    o[t].a=0;
                    t++;
                }
                else if(o[m].a>o[t].a){

                    sum+=o[m].a;
                    v-=2*(o[m].a);
                    o[t].a-=o[m].a;
                    o[m].a=0;
                    m--;
                }
                else{
                    sum+=o[t].a;
                    v-=2*(o[t].a);
                    o[m].a=0;
                    o[t].a=0;


                    t++;
                    m--;

                }
            }
            else{
                if(o[m].a>o[t].a){
                    v-=2*(o[t].a);
                    o[m].a-=o[t].a;
                    o[t].a=0;
                    t++;
                }
                else if(o[m].a>o[t].a){


                    v-=2*(o[m].a);
                    o[t].a-=o[m].a;
                    o[m].a=0;
                    m--;
                }
                else{
                    v-=2*(o[t].a);
                    o[m].a=0;
                    o[t].a=0;


                    t++;
                    m--;
                }
            }
        }
        else if(c%2==0){

            if(o[t].b!=o[m].b){

                if(o[m].a>o[t].a){
                    sum+=o[t].a;
                    v-=2*(o[t].a);
                    o[m].a-=o[t].a;
                    o[t].a=0;
                    t++;
                }
                else if(o[m].a>o[t].a){

                    sum+=o[m].a;
                    v-=2*(o[m].a);
                    o[t].a-=o[m].a;
                    o[m].a=0;
                    m--;
                }
                else{
                    sum+=o[t].a;
                    v-=2*(o[t].a);
                    o[m].a=0;
                    o[t].a=0;


                    t++;
                    m--;

                }
            }
            else{
                if(o[m].a>o[t].a){
                    v-=2*(o[t].a);
                    o[m].a-=o[t].a;
                    o[t].a=0;
                    t++;
                }
                else if(o[m].a>o[t].a){


                    v-=2*(o[m].a);
                    o[t].a-=o[m].a;
                    o[m].a=0;
                    m--;
                }
                else{
                    v-=2*(o[t].a);
                    o[m].a=0;
                    o[t].a=0;


                    t++;
                    m--;
                }
            }
        }
    }

    //while(c>0){
        //if(n){
            //int t=m+1;
            //for(int i=m;i>=1;i--){
                //if(o[i].b!=o[t].b){
                   //if(o[i].a>o[t].a){
                        //sum+=o[i].a-o[t].a;
                        //o[i].a-=o[t].a;
                        //c-=(o[t].a+o[t].a);
                        //t++;
                        //i++;
                    //}
                    //else{
                        //sum+=o[t].a-o[i].a;
                        //o[t].a-=o[i].a;
                        //c-=(o[i].a+o[i].a);
                    //}
                //}
                //else{
                   // if(o[i].a>o[t].a){
                    //    o[i].a-=o[t].a;
                       // c-=(o[t].a+o[t].a);
                       // i++;
                        //t++;

                    //}
                   // else{
                       // o[t].a-=o[i].a;
                        //c-=(o[i].a+o[i].a);
                    //}
                //}
            //}
            //break;
        //}
   // }
    cout<<sum;
    return 0;
}
