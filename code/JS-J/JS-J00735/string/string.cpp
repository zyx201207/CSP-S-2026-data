#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a=0,B=0;
    string C="";
    cin>>a;
    vector<long long> b;
    vector<string> c;
    long long left=0,right=a-1,s=0;
    for(long long i=0;i<a;i++){
        cin>>B>>C;
        b.push_back(B);
        c.push_back(C);
    }
    while(left<right){
        if(c[left]!=c[right]){
            s += min(b[left],b[right]);
        }
        if(b[left]>b[right]){
            b[left] -= b[right];
            b[right] = 0;
            right--;
        }
        else if(b[left]<b[right]){
            b[right] -= b[left];
            b[left] = 0;
            left++;
        }
        else{
            b[left] = 0;
            b[right] = 0;
            left++;
            right--;
        }
    }
    cout<<s;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
