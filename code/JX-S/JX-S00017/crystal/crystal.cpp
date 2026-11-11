include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    int a[n],s[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        s[i]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    for(int i=1;i<n;i++){
        int b=i;
        int j=m;
        while(b>0){
            if((j+a[b-1])>=a[i]){
                j-=(a[i]-a[b-1]);
                s[i]++;
                b--;
            }
            else{
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]<s[j]){
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
    }

    cout<<s[0];
    return 0;
}
