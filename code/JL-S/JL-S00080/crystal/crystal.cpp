#include <bits/stdc++.h>
using namespace std;
int process(int n,long long m,long long *s){
    int re=1;
    for(int i=1;i<=n-1;i++){
        int tmp=1;
        long long cha=s[i]-s[i-1];
        while(i-tmp>=0 && cha<=m){
            if(i-tmp>0){cha+=s[i]-s[i-tmp-1];}
            tmp++;
        }
        re=max(re,tmp);
    }
    return re;
}
int AB(int n,long long m,long long samecha){
    int re=1;
    int he=1;
    while(re<n && (he*samecha)<=m){
        re++; he+=re;
        //cout<<re<<" "<<he<<endl;
    }
    return re;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    scanf("%d",&n);
    long long m; cin>>m;
    long long *s=new long long[n];
    for(int i=0;i<=n-1;i++){
        cin>>s[i];
    }
    /*for(int i=0;i<=499999;i++){
        s[i]=(long long)(i+1)*2;
    }*/
    sort(s,s+n);
    int re;
    if(n==1){re=1;}
    else{
        long long samecha=s[1]-s[0]; int ion=1;
        for(int i=1;i<=n-1;i++){
            if(s[i]-s[i-1]!=samecha){ion=0;}
        }
        if(ion){re=AB(n,m,samecha);}
        else {re=process(n,m,s);}
    }

    cout<<re;
    return 0;
}
