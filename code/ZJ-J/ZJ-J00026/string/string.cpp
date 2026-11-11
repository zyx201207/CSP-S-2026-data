/*
I think t3 is easier --8:45
i think i know it --8:48
nope --8:54
back at 9:44
nonono i have no idea
---
back to computer at 9:51
9:55 have some idea about sum(a[i]) is odd
11:50 no
expected 68pts
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    long long s=0;
    int _=-1;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i],s+=a[i],_=max(_,a[i]);
    //brute force first,look t4: 10:03
    //this is for (expected) 56([56,68])pts
    if((long long)n*_<=1e8){
    string str;
    for(int i=1;i<=n;i++)
        for(int j=0;j<a[i];j++)
            str+='#',str+=b[i],s++;
    str+='#',s++;
    int mid=s/2;
    long long cnt=0;
    for(int i=mid,j=mid;i>=0&&j<str.size();i--,j++)
        if(str[i]!=str[j])
            cnt++;
    cout<<cnt<<'\n';
    }else{
    int mid=s/2;
    long long cnt=0;
        int sum=0,pos=1;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum>=mid){pos=i;break;}
        }
        int aa=mid-sum+a[pos],bb=sum-mid-1;
        int sub=min(aa,bb);
        int rem=0;
        if(aa>bb){
            rem=aa-bb;
            if(b[pos+1]!=b[pos])a[pos+1]-=rem;
            cnt+=rem;
        }else if(aa==bb){
            ;
        }else{
            rem=bb-aa;
            if(b[pos-1]!=b[pos])a[pos-1]-=rem;
            cnt+=rem;
        }
        //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        for(int i=pos,j=pos;i>=0&&j<=n;){
            if(b[i]!=b[j]){
                if(a[i]>a[j]){
                    a[i]-=a[j];cnt+=a[j]*2;
                    a[j]=0;
                    j++;
                }else if(a[i]<a[j]){
                    a[j]-=a[i];cnt+=a[i]*2;
                    a[i]=0;
                    i--;
                }else{
                    cnt+=a[i]+a[j];a[i]=a[j]=0;
                    i--,j++;
                }
            }else{
                if(a[i]>a[j]){
                    a[i]-=a[j];
                    a[j]=0;
                    j++;
                }else if(a[i]<a[j]){
                    a[j]-=a[i];
                    a[i]=0;
                    i--;
                }else{
                    a[i]=a[j]=0;
                    i--,j++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}