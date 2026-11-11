#ifndef STRING_CPP_INCLUDED
#define STRING_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
struct md{
    int a;
    char b;
}m[2001];
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i].a>>m[i].b;
    }
    int j=n-1,mint=0;
    for(int i=0;i<j;){
        if(m[i].b==m[j].b){
            if(m[i].a<m[j].a){
                m[j].a-=m[i].a;
                i++;
                continue;
            }
            else if(m[i].a>m[j].a){
                m[i].a-=m[j].a;
                j--;
                continue;
            }
            else{
                i++;
                j--;
                continue;
            }
        }else{
            if(m[i].a<m[j].a){
                m[j].a-=m[i].a;
                mint+=m[i].a;
                i++;
                continue;
            }
            else if(m[i].a>m[j].a){
                m[i].a-=m[j].a;
                mint+=m[j].a;
                j--;
                continue;
            }
            else{
                mint+=m[i].a;
                i++;
                j--;
                continue;
            }
        }
    }
    cout << mint;
    return 0;
}


#endif // STRING_CPP_INCLUDED
