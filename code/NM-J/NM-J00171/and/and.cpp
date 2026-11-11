#include<bits/stdc++.h>
using namespace std;
/*int And(int a,int b){
    string s1,s2;
    s1=erjinzhi(a);
    s2=erjinzhi(b);

}
string  erjinzhi(int a){
    string s;
    int i=0;
    char b[];
    while(a!=0){
        b[i]=char(a%2);
        a/=2;
        ++i;
    }int p=-1;
    for(int o=i;o>-1;--o){
        s.insert(++p,b[o]);
    }
}*/
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            a[i]&=b[j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<a[n-1];
    return 0;
}
