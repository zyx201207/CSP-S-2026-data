#include<bits/stdc++.h>   // May MLE?
using namespace std;
long long n;
long long a[200005];
long long fr[200005];
long long sum;
long long change;
char cha[200005];
bool odd;
long long findAimIndex(long long mid,long long cache=-1){   // O(n) with no cache,O(1) with cache
    if(cache!=-1){
        if(cache!=1){
            if(fr[cache-1]>=mid){
                return cache-1;
            }
        }
        if(fr[cache]>=mid){
            return cache;
        }
        else if(fr[cache+1]>=mid){
            return cache+1;
        }
        else{
            return -1;
        }
        
    }
    else{
    for(long long i=1;i<=n;i++){
        if(fr[i]>=mid){
            return i;
        }
    }
    }
    return -1;
}

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&cha[i]);
        sum+=a[i];
        fr[i]=sum;
    }
    if(sum%2==0){
        odd=true;
    }
    else odd=false;
    long long mid=(odd? sum/2:(sum+1)/2);
    long long room=findAimIndex(mid);

    if(odd){
        long long Oroom=room;
        for(long long i=mid,j=mid+1;;){
            long long room1=findAimIndex(i,room);
            long long room2=findAimIndex(j,Oroom);
            if(room1==-1||room2==-1) break;
            long long mino=min(i-fr[room1-1],fr[room2]-j+1);
            if(cha[room1]!=cha[room2]){
                change+=mino;
            }
            i-=mino;
            j+=mino;
            room=room1;
            Oroom=room2;
        }
    }
    else{
        long long Oroom=room;
        for(long long i=mid-1,j=mid+1;;){
            long long room1=findAimIndex(i,room);
            long long room2=findAimIndex(j,Oroom);
            if(room1==-1||room2==-1) break;
            long long mino=min(i-fr[room1-1],fr[room2]-j+1);
            if(cha[room1]!=cha[room2]){
                change+=mino;
            }
            i-=mino;
            j+=mino;
            room=room1;
            Oroom=room2;
        }
    }
    cout<< change <<endl;
    return 0;
}