#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
}si[100000000];
char cl[100000000];
char cl1[100000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long x1=0;
    long long x2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>si[i].a;
        cin>>si[i].c;
    }
    for(int i=0;i<n;i++){
        while(si[i].a>0){
            cl[x1]=si[i].c;
            x1++;
        }
    }
    x2=x1-1;
    for(long long i=0;i<x1;i++){
        cl1[i]=cl[x2];
        x2--;
    }
    long long fa=0;
    for(long long i=0;i<x1;i++){
        if(cl1[i]!=cl[i]){
            fa++;
        }
    }
    cout<<fa<<endl;
    return 0;
}
