#include<bits/stdc++.h>
using namespace std;
long long n;
long long lastnumbp[200005],lastnumbp2[200005];
char lastcp[200005],lastcp2[200005];
long long ans=0;
struct Node{
    long long numb;
    char c;
}p[200005];
struct Node2{
    long long numb;
    char c;
}p2[200005];
int cur=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].numb>>p[i].c;
        p2[n-i+1].numb=p[i].numb;
        p2[n-i+1].c=p[i].c;
    }
    for(int i=1;i<=n;i++){
        for(int j=cur;j<i&&p2[i].numb>0&&p[i].numb>0;j++){
            if(lastnumbp[j]>0){
                if(p2[i].c==lastcp[j]){
                    if(lastnumbp[j]>=p2[i].numb){
                        lastnumbp[j]-=p2[i].numb;
                        p2[i].numb=0;
                    }else{
                        p2[i].numb-=lastnumbp[j];
                        lastnumbp[j]=0;
                        cur++;
                    }
                }else{
                    ans+=min(lastnumbp[j],p2[i].numb);
                    if(lastnumbp[j]<=p2[i].numb){
                        p2[i].numb-=lastnumbp[j];
                        lastnumbp[j]=0;
                        cur++;
                    }else{
                        lastnumbp[j]-=p2[i].numb;
                        p2[i].numb=0;
                    }
                }
            }
            else if(lastnumbp2[j]>0){
                if(p[i].c==lastcp2[j]){
                    if(lastnumbp2[j]>=p[i].numb){
                        lastnumbp2[j]-=p[i].numb;
                        p[i].numb=0;
                    }else{
                        p[i].numb-=lastnumbp2[j];
                        lastnumbp2[j]=0;
                        cur++;
                    }
                }else{
                    ans+=min(lastnumbp2[j],p[i].numb);
                    if(lastnumbp2[j]<=p[i].numb){
                        p[i].numb-=lastnumbp2[j];
                        lastnumbp2[j]=0;
                        cur++;
                    }else{
                        lastnumbp2[j]-=p[i].numb;
                        p[i].numb=0;
                    }
                }
            }
        }
        if(p2[i].numb>0||p[i].numb>0){
            if(p2[i].c==p[i].c){
                lastnumbp[i]=p[i].numb-p2[i].numb;
                lastnumbp2[i]=p2[i].numb-p[i].numb;
                lastcp[i]=p[i].c;
                lastcp2[i]=p[i].c;
            }else{
                lastnumbp[i]=p[i].numb-p2[i].numb;
                lastnumbp2[i]=p2[i].numb-p[i].numb;
                lastcp[i]=p[i].c;
                lastcp2[i]=p2[i].c;
                ans+=min(p[i].numb,p2[i].numb);
            }
        }
    }cout<<ans/2;
    return 0;
}
