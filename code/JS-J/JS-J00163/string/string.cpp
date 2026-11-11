#include<bits/stdc++.h>
using namespace std;
ifstream fin("string.in");
ofstream fout("string.out");
int a[200005];
char c[200005];
int main(){
    int n;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a[i]>>c[i];
    }
    long long ans=0;
    int left=1,r=n;
    while(left!=r){
        if(c[left]==c[r]){
            if(a[left]==a[r]){
                left++;
                r--;
            }
            if(a[left]>a[r]){
                a[left]=a[left]-a[r];
                r--;
            }
            if(a[left]<a[r]){
                a[r]=a[r]-a[left];
                left++;
            }
        }
        if(c[left]!=c[r]){
            if(a[left]==a[r]){
                ans+=a[left];
                left++;
                r--;
            }
            if(a[left]>a[r]){
                ans+=a[r];
                a[left]=a[left]-a[r];
                r--;
            }
            if(a[left]<a[r]){
                ans+=a[left];
                a[r]=a[r]-a[left];
                left++;
            }
        }
    }
    fout<<ans;
}
