#include<bits/stdc++.h>
using namespace std;
long long ans,num;
struct node{
    long long start,endd;
    char c;
}line[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        line[i].c=c;
        line[i].start=line[i-1].endd+1;
        line[i].endd=line[i].start+x-1;
        ans+=x;
    }
    long long i=1,j=n,ii=1,jj=ans;
    long long mid1=ans/2;
    long long mid2=mid1+1;
    if(ans%2==1)mid2++;
    while(ii<mid1&&jj>mid2){
        int x1=int(line[i].c-'a')+1;
        long long w=line[i].endd-line[i].start+1;
        if(ii+w-1>mid1)ii=mid1;
        else{
            ii+=w-1;
            i++;
        }
        while(jj-mid2>mid1-ii){
            int u=line[j].endd-line[j].start+1;
            int x2=int(line[j].c-'a')+1;
            if(line[j].start-mid2-1>=mid1-ii){
                if(x1!=x2)num+=jj-line[j].start+1;
                jj=line[j].start;
                j--;
            }
            else{
                if(x1!=x2)num+=jj-(mid1-ii+mid2);
                jj=mid1-ii+mid2;
            }
        }
    }
    cout<<num;
    return 0;
}

