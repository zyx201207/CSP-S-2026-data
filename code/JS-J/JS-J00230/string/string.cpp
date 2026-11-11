#include<bits/stdc++.h>
#include<fstream>
int main(){
    std::ifstream fin("string.in");
    std::ofstream fout("string.out");
    long long n;
    fin>>n;
    int a[n];
    char c[n];
    long long sum=0;
    for(int i=0;i<n;i++){
        fin>>a[i];
        fin>>c[i];
    }
    int i=n-1;
    int j=0;
    while(i>j){
        if(c[i]==c[j]){
            if(a[i]==a[j]){
                i--;
                j++;
            }
            else if(a[i]>a[j]){
                a[i]-=a[j];
                j++;
            }
            else{
                a[j]-=a[i];
                i--;
            }
        }
        else{
            if(a[i]==a[j]){
                sum+=a[j];
                j++;
                i--;
            }
            else if(a[i]>a[j]){
                sum+=a[j];
                a[i]-=a[j];
                j++;
            }
            else{
                sum+=a[i];
                a[j]-=a[i];
                i--;
            }
        }
    }
    fout<<sum;
    return 0;
}
