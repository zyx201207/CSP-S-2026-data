#include<bits/stdc++.h>
using namespace std;
int n;
int minn=0;
int main(){
    freopem("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long num=0;
    long long a[n]; char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
    }
    if(num/2!=0) num+=1;

    int bb=0;//take "s" back
    char s1[num],s2[num];
    for(int i=n-1;i>=0;i--){//s2
        for(int l=0;l<a[i];l++){
            s2[bb]=c[i]; bb++;
        }
    }
    bb=0;
    for(int i=0;i<n;i++){//s1
        for(int l=0;l<a[i];l++){
            s1[bb]=c[i]; bb++;
        }
    }

    //hou many mistakes
    for(int i=0;i<num/2;i++){
        if(s1[i]!=s2[i]) minn++;
    }
    cout<<minn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

