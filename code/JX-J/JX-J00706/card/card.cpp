#include<bits/stdc++.h>
using namespace std;
int a1[300005];
int a2[300005];
int a[200005];
string n1;
string s;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int n2=n;
    while(n2--){
        for(int i=n-n2;i<=n;i++){
            if(a1[a[i]]>=1){
                    for(int i1=0;i1<n1.size();i1++){
                        if((int)n[i1]-'0'==a[i]){
                            for(int j=i1;j<n1.size();j++){
                                a1[int(n[j]-'0')]--;
                                n[j]=0;
                            }
                            break;
                        }
                    }
            }
            n1+=char(a[i]+'0');
            a1[a[i]]++;
        }
        int l=n1.size();
        cout<<n1<<"\n";
        for(int i=0;i<l;i++){
            a2[n1[i]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
       if(a2[i]){
          cout<<a2[i]<<" ";
       }
    }
    return 0;
}
