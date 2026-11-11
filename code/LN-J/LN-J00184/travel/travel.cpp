#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,s1,s2,s3,s4;
    int f=0,flag=0;
    cin>>a>>b>>c>>d;
    cout<<(a==c);
    for(int i=0;i<b.size();i++){
        if(b[i]>='0' and b[i]<='9'){
            s1+=b[i];
        }
        else if(b[i]>='A' and b[i]<='F'){
            s3+=b[i];
        }
    }
    for(int i=0;i<d.size();i++){
        if(d[i]>='0' and d[i]<='9'){
            s2+=d[i];
        }
        else if(d[i]>='A' and d[i]<='F'){
            s4+=d[i];
        }
    }

    cout<<(s1==s2 and a==c);
    if(((s3=="A" or s3=="B" or s3=="C") and (s4=="A" or s4=="B" or s4=="C")) or ((s3=="D" or s3=="F") and (s4=="D" or s4=="F")) and s1==s2 and a==c)
        f=1;
    cout<<(s1==s2 and a==c and f==1);
    if((s3=="A" and s4=="B") or (s3=="B" and s4=="A") or (s3=="B" and s4=="C") or (s3=="C" and s4=="B") or (s3=="D" and s4=="F") or (s3=="F" and s4=="D")){
        if(s1==s2 and a==c and f==1)
            flag=1;
    }
    cout<<(s1==s2 and a==c and f==1 and flag==1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
