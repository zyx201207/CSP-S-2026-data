#include<bits/stdc++.h>
using namespace std;
const int p=2e5+10;
struct stu{
    int s;
    char z;
}t[p];
string  s1;
string s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++){
        cin>>t[i].s>>t[i].z;
        k+=t[i].s;
    }
    cout<<0;
    int mid=k/2;
    int y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<t[i].s;j++){
            s1[y]=t[j].z;
            y++;
        }
    }int u=0;
    for(int i=p;i>0;i--){
        if(k>=mid){
            s2[u++]=t[i].s;
            k--;
        }
        else{
            break;
        }
    }
    int g=0;
    for(int i=0;i<=mid-1;i++){
        if(t[i].z !=t[i+1].z){
            g++;
        }
    }
    int  b=0;
    for(int i=mid;i<=k-1;i++){
        if(t[i].z !=t[i+1].z){
            b++;
        }
    }
    int  l=0;
    if(g>b){
        for(int i=p;i>0;i--){
            if(s1[i] != s2[i] ){
                    l++;
            }
        }
    }
    if(g<b){
        for(int i=p;i>0;i--){
            if(s1[i] != s2[i] ){
                    l++;
            }
        }
    }
    cout<<l;
    return 0;
}


