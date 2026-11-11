#include<bits/stdc++.h>
using namespace std;

imt main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,s;
    cin>>n>>s;
    int a[n],m=0,ma[s];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<s;i++){
        m=m+a[i+1]-a[i];
    }
    for(int i=0;i<n-s;i++){
        int ca=0;
        for(int j=i;j<i+s-1;j++){
            ca=ca+a[j+1]-a[j];
            if(ca<=m){
                m=ca;
                for(int q=0;q<s;q++){
                    ma[q]=a[j+q];
                }
            }
        }
    }
    for(int i=0;i<s;i++){
        int t=ma[i],sq10=1;
        ma[i]=0;
        while(t>0){
            ma[i]+=t%2*sq10;
            t=t/2;
            sq10=sq10*10;
        }

    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}
