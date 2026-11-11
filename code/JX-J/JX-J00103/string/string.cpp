#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in",r,stdin);
    freopen("string.out",r,stdout);
    long long q,p,r=0,t;
    string a;
    cin>>q;
    p=q;
    long long q1[q];
    char q2[q];
    for(long long i=0;i<q;i++){
        cin>>t>>q2[i];
        if(q2[i]==q2[i-1]){
            q1[r]+=t;
            p--;
        }
        else{
            r++;
        }
    }
    if(p>2){
        for(int i=0;i<p;i++){
            for(long long j=0;j<q1[i];j++){
                a=a+q2[i];
            }
        }
        long long sum=0,asize=a.size();
        for(long long i=0;i<asize;i++){
            if(a[i]!=a[asize-1-i]){
                sum++;
            }
        }
        cout<<sum/2;
    }
    else if(p==2){
        cout<<min(q1[0],q1[1]);
    }
    else if(p==1){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
