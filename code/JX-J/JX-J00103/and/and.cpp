#include<bits/stdc++.h>
using namespace std;
bool qwe(long long q,long long a){
    return q>a;
}
string q_2(long long q){
    string a,a1;
    while(q>0){
        a=char(q%2+'0')+a;
        q=q/2;
    }
    for(int i=a.size()-1;i>=0;i--){
        a1=a[i]+a1;
    }
    return a1;
}
long long qq(string q){
    long long snm=0;
    for(int i=0;i<q.size();i++){
        snm=snm*2+int(q[i]-'0');
    }
    return snm;
}
int main(){
    freopen("and.in",r,stdin);
    freopen("and.out",r,stdout);
    long long n,m;
    cin>>n>>m;
    string a1,a2,a3;
    long long a[n],nm[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,qwe);
    for(int i=0;i<m;i++){
        nm[i]=a[i];
    }
    for(int i=1;i<m;i++){
        if(i==1){
            a2=q_2(nm[0]);
            a3=q_2(nm[i]);
            string qa;
            for(int i=0;i<min(a2.size(),a3.size());i++){
                if(a2[i]==a3[i]){
                    qa='1'+qa;
                }
                else{
                    qa='0'+qa;
                }
            }
            a1=qa;
        }
        else{
            a2=q_2(nm[i]);
            string qa;
            for(int i=0;i<min(a2.size(),a1.size());i++){
                if(a1[i]==a2[i]){
                    qa='1'+qa;
                }
                else{
                    qa='0'+qa;
                }
            }
            a1=qa;
        }
    }
    cout<<qq(a1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
